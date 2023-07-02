#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <pthread.h>

namespace ns_thread_pool
{
    const int g_num = 5;
    template <class T>
    class ThreadPool
    {
    private:
        int num_;                  // 预先创建线程的数量
        std::queue<T> task_queue_; // 任务队列----》是一个临界资源
        pthread_mutex_t mtx_;      // 一把锁
        pthread_cond_t cond_;      // 条件变量

        static ThreadPool<T> *ins; // 类内的静态指针

        // 构造函数必须得实现，但是必须得私有化
        ThreadPool(int num = g_num)
            : num_(num)
        {
            pthread_mutex_init(&mtx_, nullptr);
            pthread_cond_init(&cond_, nullptr);
        }
        ThreadPool(const ThreadPool<T> &tp) = delete;
        // 赋值语句
        ThreadPool<T> &operator()(ThreadPool<T> &tp) = delete;

    public:
        static ThreadPool<T> *GetInstance()
        {
            static pthread_mutex_t lock = PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP;
            // 当前单例对象还没有被创建
            if (ins == nullptr)
            {
                pthread_mutex_lock(&lock);
                if (ins == nullptr)
                {
                    ins = new ThreadPool<T>();
                    ins->InitThreadPool();
                }
                pthread_mutex_unlock(&lock);
            }
            return ins;
        }
        void Lock()
        {
            pthread_mutex_lock(&mtx_);
        }
        void Unlock()
        {
            pthread_mutex_unlock(&mtx_);
        }
        bool IsEmpty()
        {
            return task_queue_.empty();
        }
        void Wait()
        {
            pthread_cond_wait(&cond_, &mtx_);
        }
        void Wakeup()
        {
            pthread_cond_signal(&cond_);
        }

    public:
        // 在类中我们要让线程执行类内成员方法，是不可行的！！！
        static void *Rountine(void *args) // 线程所要执行的任务
        {
            // 这次我不在让我们的主线程去等这些创建出来的线程了，我们将创建的线程进行分离
            // 主线程继续往后走，执行任务的线程去执行任务
            pthread_detach(pthread_self());
            ThreadPool<T> *tp = (ThreadPool<T> *)args;
            while (true)
            {
                tp->Lock();
                while (tp->IsEmpty()) // while循环防止伪唤醒
                {
                    // 检测到任务队列为空，此时线程该做什么呢？？  --》 让我们的线程在条件变量下挂起
                    tp->Wait();
                }
                // 到这一步，该任务队列一定是有任务了
                T t;
                tp->PopTask(&t); // 此时我们就可以拿到我们任务队列当中的任务了
                tp->Unlock();
                t.Run(); // 任务已经拿到你线程的上下文了，不在属于临界资源了
            }
        }
        void InitThreadPool() // 初始化线程池
        {
            pthread_t tid;
            for (int i = 0; i < num_; i++)
            {
                pthread_create(&tid, nullptr, Rountine, (void *)this);
            }
        }
        void PushTask(const T &in) // 外面的线程往队列当放任务，通过这个接口
        {
            Lock();
            task_queue_.push(in);
            Unlock();
            Wakeup(); // 唤醒在条件变量下等待的线程
        }
        void PopTask(T *out)
        {
            *out = task_queue_.front();
            task_queue_.pop();
        }
        ~ThreadPool()
        {
            pthread_mutex_destroy(&mtx_);
            pthread_cond_destroy(&cond_);
        }
    };

    template <class T>
    ThreadPool<T> *ThreadPool<T>::ins = nullptr; // 对static类内的指针初始化
}
