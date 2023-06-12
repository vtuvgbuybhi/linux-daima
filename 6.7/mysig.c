#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

void Getchild(int signo)
{
  printf("get a signo :%d  pid: %d\n",signo,getpid());
}

int main()
{
//var  signal(17,Getchild);
  signal(SIGCHLD,SIG_IGN);
  pid_t id=fork();
  if(id==0){//child
    int count=5;
    while(count--){
      printf("我是子进程: %d\n",getpid());
      sleep(1);
    }
    exit(0);
  }
  
  while(1);
  return 0;
}



















//volatile int flag=0;
//
//void handler(int signo){
//  flag=1;
//  printf("change flag 0 to 1\n");
//}
//
//
//int main()
//{
//  signal(2,handler);
//  while(!flag);
//
//  printf("这个进程是正常退出的！！\n");
//
//  return 0;
//}


//varvoid handler(int signo)
//var{
//var  printf("get a signo : %d\n",signo);
//var}
//var
//varint main()
//var{
//var  struct sigaction act;
//var  memset(&act,0,sizeof(act));
//var  act.sa_handler=handler;
//var
//var  //本质是修改当前进程的handler函数指针数组特定的内容
//var  sigaction(2,&act,NULL);
//var
//var  while(1){
//var    printf("hello bit\n");
//var    sleep(1);
//var  }
//var
//var  return 0;
//var}
//var

//void show_pending(sigset_t *set)
//{
//  printf("curr process pending: ");
//  for(int i=1;i<=31;i++){
//    if(sigismember(set,i)){
//      printf("1");
//    }
//    else{
//      printf("0");
//    }
//  }
//  printf("\n");
//}
//
//
//int main()
//{
//  sigset_t iset, oset; 
//  
//  sigemptyset(&iset);
//  sigemptyset(&oset);
//
//  sigaddset(&iset,2);
//
//  sigprocmask(SIG_SETMASK,&iset,&oset);
//
//  sigset_t pending;
//  int count=0;
//  while(1){
//    sigemptyset(&pending);
//    
//    sigpending(&pending);
//    show_pending(&pending);
//    sleep(1);
//    count++;
//    if(count==20){
//      sigprocmask(SIG_SETMASK,&oset,NULL);
//      printf("恢复2号信号，可以被递达\n");
//    }
//  }
//
//  return 0;
//}


//int main()
//{
////  sigset_t set; 
////  set |=1;
//
//  sigset_t iset, oset; 
//  
//  sigemptyset(&iset);
//  sigemptyset(&oset);
//
//  sigaddset(&iset,2);
//  sigaddset(&iset,9);
//
//  sigprocmask(SIG_SETMASK,&iset,&oset);
//  while(1){
//    printf("hello cdc\n");
//    sleep(1);
//  }
//
//  return 0;
//}


