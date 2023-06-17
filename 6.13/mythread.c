#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#define NUM 1

void* thread_run(void* args)
{
  while(1){
    printf("[%s] ID :0x%x\n",(const char*)args,pthread_self());
    sleep(2);
  }
}

int main()
{

  pthread_t tid;
  pthread_create(&tid,NULL,thread_run,"new thread");

  while(1){
    printf("thread main ID :0x%x\n",pthread_self());
    sleep(1);
  }

  return 0;
}














//void* thread_run(void* args)
//{
//  pthread_detach(pthread_self());
//  int num=*(int*)args;
//  while(1){
//    printf("我是新线程[%d]，我的线程ID是 :%lu\n",num,pthread_self());
//    sleep(2);
//    break;
//    }
////  exit(123);
////  pthread_exit((void*)123);
//  return (void*)111;
//}
//
//int main()
//{
//  pthread_t tid[NUM];
//  for(int i=0;i<NUM;i++){
//    pthread_create(tid+i,NULL,thread_run,(void*)&i);
//    sleep(1);
//  }
//  printf("wait sub thread....\n");
//  sleep(5);
//  printf("cancel sub thread...\n");
////  pthread_cancel(tid[0]);
//  void*status=NULL;
//  int ret=0;
//  ret=pthread_join(tid[0],&status);
//  printf("ret :%d  ,status : %d\n",ret,(int)status);
//  sleep(3);
////  while(1){
////    printf("我是主线程,我的thread ID：%lu\n",pthread_self());
////    printf("######################begin###########################\n");
////    for(int i=0;i<NUM;i++){
////      printf("我创建的线程[%d]是: %lu\n",i,tid[i]);
////    }
////    printf("########################end##########################\n");
////    sleep(1);
////  }
//
//
//  return 0;
//}
//


//void* thread_run(void* args)
//{
//  int num=*(int*)args;
//  while(1){
//    printf("我是新线程[%d]，我的线程ID是 :%lu\n",num,pthread_self());
//    sleep(3);
//    //野指针问题
//    if(num==3){
//      printf("thread number :%d\n quit",num);
//      int*p=NULL;
//      *p=1000;
//    } 
//  }
//}
//
//int main()
//{
//  pthread_t tid[NUM];
//  for(int i=0;i<NUM;i++){
//    pthread_create(tid+i,NULL,thread_run,(void*)&i);
//    sleep(1);
//  }
//  while(1){
//    printf("我是主线程,我的thread ID：%lu\n",pthread_self());
//    printf("######################begin###########################\n");
//    for(int i=0;i<NUM;i++){
//      printf("我创建的线程[%d]是: %lu\n",i,tid[i]);
//    }
//    printf("########################end##########################\n");
//    sleep(1);
//  }
//
//
//  return 0;
//}









//void *thread_run(void* args)
//{
//  const char*id=(const char*)args;
//  while(1){
//    printf("我是%s线程，%d\n",id,getpid());
//    sleep(1);
//  }
//}
//
//
//int main()
//{
//  pthread_t tid;
//
//  pthread_create(&tid,NULL,thread_run,(void*)"thread 1");
//
//  while(1){
//    printf("我是main线程，%d\n",getpid());
//    sleep(1);
//  }
//
//  return 0;
//}


