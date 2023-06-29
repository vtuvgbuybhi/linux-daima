#include<iostream>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
//using namespace std
pthread_mutex_t mtx;
pthread_cond_t cond;

void* ctrl(void *args){
    std::string name=(char*)args;
    while(true){
        //唤醒在条件变量下等待的一个线程，哪一个？？
        std::cout<<"master say : begin work"<<std::endl;
        //pthread_cond_signal(&cond);
        pthread_cond_broadcast(&cond);
        sleep(1);        
    }
}
void* work(void *args){
    int number=*(int*)args;
    delete (int*)args;
    while(true){
        pthread_cond_wait(&cond,&mtx);//
        std::cout<<"worker: "<< number <<"is working..."<<std::endl;
    }
}

int main()
{
#define NUM 3
    pthread_mutex_init(&mtx,nullptr);
    pthread_cond_init(&cond,nullptr);

    pthread_t worker[NUM];
    pthread_t master;
    pthread_create(&master,nullptr,ctrl,(void*)"boss");
    for(int i=0 ; i<NUM ; i++){
        int *number=new int(i);
        pthread_create(worker+i , nullptr , work ,(void*)number);
    }
    for(int i=0;i<NUM ;i++){
        pthread_join(worker[i],nullptr);
    }

    pthread_join(master,nullptr);

    pthread_mutex_destroy(&mtx);
    pthread_cond_destroy(&cond);

    return 0;
}

