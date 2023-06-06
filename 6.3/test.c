#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int count =0;

void Handler(int signo)
{
  printf(" hello : %d\n",count);
  exit(1);
}

int main()
{
  signal(SIGALRM,Handler);
  alarm(1);
  while(1){
    count++;
   //printf("hello : %d\n",count++);
  }
  return 0;
}








//void handler(int signo)
//{ 
//  switch(signo){
//    case 2:
//      printf("hello cdc ,get a signal : %d\n",signo);
//      break;
//    case 3:
//      printf("helli cdc ,get a signal : %d\n",signo);
//      break;
//    case 9:
//      printf("hello  ... get a signal : %d\n",signo);
//      break;
//    default:
//      printf("hello signo : %d  , getpid : %d\n",signo,getpid());
//      break;
//  }
//  exit(1);
//}
//int main()
//{
//  int sig=1;
//  for( ;sig<= 31 ;sig++)
//  {
//    signal(sig,handler);
//  }
//
//  int ret=alarm(30);
//
//  while(1){ 
//    printf("hello world , pid:%d ret : %d\n\n",getpid(),ret);
//    sleep(1);
//    int res=alarm(0);
//    printf("res: %d\n",res);
//  }
//  return 0;
//}
//




//static void Usage(const char* proc)
//{
//  printf("Usage: \n\t %s signo who \n",proc);
//}
//
//int main(int argc,char* argv[])
//{
//  while(1){
//    printf("I am a process\n");
//    sleep(3);
//    raise(8);
//  }
//
//  return 0;
//  if(argc!=3){
//    Usage(argv[0]);
//    return 1;
//  }
//
//  int signo = atoi(argv[1]);
//  int who=atoi(argv[2]);
//  
//  kill(who,signo);
//
//  printf("signo : %d ,who : %d\n",signo, who);
//
//  return 0;
//}



//int main()
//{
//  if(fork()==0){
//    while(1){
//      printf("I am child ...\n");
//      int a=10;
//      a/=0;
//    }
//  }
//  int status=0;
//  waitpid(-1,&status,0);
//  printf("exit code : %d ,exit sig : %d , core dump flag : %d\n",(status>>8)&0xff,(status)&0x7f,(status>>7)&1);
//  return 0;
//}


//void handler(int signo)
//{ 
//  switch(signo){
//    case 2:
//      printf("hello cdc ,get a signal : %d\n",signo);
//      break;
//    case 3:
//      printf("helli cdc ,get a signal : %d\n",signo);
//      break;
//    case 9:
//      printf("hello  ... get a signal : %d\n",signo);
//      break;
//    default:
//      printf("hello signo : %d  , getpid : %d\n",signo,getpid());
//      break;
//  }
//  exit(1);
//}
//int main()
//{
////  int sig=1;
////  for( ;sig<= 31 ;sig++)
////  {
////    signal(sig,handler);
////  }
//
//  while(1){ 
////    int *p=NULL;
////    p=(int*)100;
////    *p=100;
////    int a=10;
////    a/=0;
//    printf("hello world , pid:%d\n\n",getpid());
//    sleep(1);
//  }
//  return 0;
//}
//
//
