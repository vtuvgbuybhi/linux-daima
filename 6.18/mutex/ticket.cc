#include<iostream>
#include<string>
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<ctime>
#include<cstdlib>

// 抢票逻辑 ，1000张票，5个线程同时抢
//tickets就是所谓的临界资源    ---》 tickets是原子的吗（是安全的吗？？）
//为了让多个进程进行切换，线程什么时候会切换（1.时间片到了  2. 检测的时间点：从内核态到用户态的时候）

//对临界区加锁
class Ticket{
    private:
    int tickets;
    pthread_mutex_t mtx;

    public:
    Ticket():tickets(1000){
        pthread_mutex_init(&mtx,nullptr);
    }
    bool GetTicket()
    {
        bool res=true;
        pthread_mutex_lock(&mtx);
        if(tickets>0){//抢票
            usleep(1000);
            std::cout<<"我是["<<pthread_self()<<"]我要抢的票是:"<<tickets<<std::endl;
            tickets--;
            printf("");
        }
        else{//没有票
            printf("票已经被抢空了\n");
            res=false;
        }
        pthread_mutex_unlock(&mtx);
        return res;
    }

    ~Ticket(){
        pthread_mutex_destroy(&mtx);
    }

};
void* ThreadRoutine(void* args)
{
    Ticket* t=(Ticket*)args;
    while(true){
        if(!t->GetTicket())
        {
            break;
        } 
    }
}
int main()
{
    Ticket *t=new Ticket(); 
    pthread_t tid[5];
    for(int i=0;i<5;i++){
        int *id=new int(i);
        pthread_create(tid+i,nullptr,ThreadRoutine,(void*)t);
    }
    for(int i=0;i<5;i++){
        pthread_join(tid[i],nullptr);
    }

    return 0;
}
