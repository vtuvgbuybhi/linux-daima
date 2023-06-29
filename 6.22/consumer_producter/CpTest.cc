#include"BlockQueue.hpp"
#include"Task.hpp"
using namespace ns_blockqueue;
using namespace ns_task;
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

void* consumer(void* args)
{
    BlockQueue<Task>* bq=(BlockQueue<Task>*)args;
    while(true)
    {
        Task t;
        bq->Pop(&t);
        t.Run();
        // sleep(2);
        // int data=0;
        // bq->Pop(&data);
        // std::cout<<"消费者消费了一个数据: "<<data<<std::endl;
    }
}
void* producter(void* args)
{
    BlockQueue<Task> *bq=(BlockQueue<Task>*)args;
    std::string ops="+-*/%";
    while(true)
    {
        int x=rand()%20+1;
        int y=rand()%10+1;
        char op=ops[rand()%5]; 
        Task t(x,y,op);
        bq->Push(t);
        sleep(1);
        //sleep(2);
        //1.制作数据
        // int data=rand()%20+1;
        // std::cout<<"生产者生产数据："<<data<<std::endl;
        // bq->Push(data);
    }
}


int main()
{
    srand((long long )time(nullptr));//种下一颗随机数种子
    BlockQueue<Task> *bq=new BlockQueue<Task>();
    pthread_t c,p;
    pthread_create(&c,nullptr,consumer,(void*)bq);
    pthread_create(&p,nullptr,producter,(void*)bq);

    pthread_join(c,nullptr);
    pthread_join(p,nullptr);

    return 0;
}



