#pragma once
#include<iostream>
#include<vector>
#include<semaphore.h>
namespace ns_ring_queue
{
    const int g_cap_default=10;
    template<class T>
    class RingQueue
    {
    private:
        std::vector<T> ring_queue_;
        int cap_;
        //生产者关心空位置资源
        sem_t blank_sem_;
        //消费者关心数据资源
        sem_t data_sem_;

        pthread_mutex_t c_mtx_;
        pthread_mutex_t p_mtx_;

        int c_step_;
        int p_step_;
    public:
        RingQueue(int cap=g_cap_default)
            :cap_(cap),
             ring_queue_(cap)
        {
            sem_init(&blank_sem_,0,10);
            sem_init(&data_sem_,0,0);
            pthread_mutex_init(&c_mtx_,nullptr);
            pthread_mutex_init(&p_mtx_,nullptr);
            c_step_=p_step_=0;
        }
        ~RingQueue()
        {
            sem_destroy(&blank_sem_);
            sem_destroy(&data_sem_);

            pthread_mutex_destroy(&c_mtx);
            pthread_mutex_destroy(&p_mtx);
        }
    public:
    //目前高优先级的先实现单生产和单消费
        void Push(const T &in)
        {
            //生产接口
            //申请信号量
            //lock()  0
            sem_wait(&blank_sem_);//P(空位置)预定资源
            //可以生产了，可是往哪个位置生产呢？？ --->这是一个环形队列
            pthread_mutex_lock(&p_mtx_);  //1
            ring_queue_[p_step_]=in;

            //它也变成了临界资源
            p_step_++;
            p_step_%=cap_;
            pthread_mutex_unlock(&p_mtx_);

            sem_post(&data_sem_);//V操作，数据多了
        }
        void Pop(T*out)
        {
            //消费接口
            sem_wait(&data_sem_);//P操作你得先申请数据资源
            pthread_mutex_lock(&c_mtx_);
            *out=ring_queue_[c_step_];

            c_step_++;
            c_step_%=cap_;
            pthread_mutex_unlock(&c_mtx_);

            sem_post(&blank_sem_);//V操作，空位置多了

        }
    };
}
