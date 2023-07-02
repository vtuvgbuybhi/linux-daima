#include "thread_pool.hpp"
#include "Task.hpp"
#include <ctime>
#include <unistd.h>
using namespace ns_thread_pool;
using namespace ns_task;
int main()
{
    // ThreadPool<Task> *tp = new ThreadPool<Task>(); // new一个ThreadPool类对象出来
    // tp->InitThreadPool();                          // 调用线程池初始化，创建出一批的线程  --> 立马我的线程池当中就会有线程出来
    srand((long long)time(nullptr));
    while (true)
    {
        // 任务从网络里来
        Task t(rand() % 20 + 1, rand() % 10 + 1, "=-*/%"[rand() % 5]);
        ThreadPool<Task>::GetInstance()->PushTask(t);
        std::cout << ThreadPool<Task>::GetInstance() << std::endl;
        // tp->PushTask(t);
        sleep(1);
    }

    return 0;
}
