#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
  if(fork()==0){
    printf("command begin...\n"); 
    //execl("./myexe","myexe",NULL);
    char* env[]={
      "MYENV=hahahahahahaha",
      "MYENV1=HAHAHAHHAHAHA",
    };
    execle("./myexe","myexe",NULL,env);
    printf("command end...\n");
    exit(1);
  };
  waitpid(-1,NULL,0);
  printf("wait child process!\n");
  return 0;
}

//int main()
//{
//  if(fork()==0){
//    printf("command begin...\n");    
//    char *argv[]={
//      "ls",
//      "-a",
//      "-l",
//      NULL
//    };
//    execvp("ls",argv);
//    printf("command end...\n");
//    exit(1);
//  };
//  waitpid(-1,NULL,0);
//  printf("wait child process!\n");
//  return 0;
//}
//

//int main()
//{
//  if(fork()==0){
//    printf("command begin...\n");
//   //binexecl("/usr/bin/ls","ls","-a","-l",NULL);
//    char *argv[]={
//      "ls",
//      "-a",
//      "-l",
//      NULL
//    };
//    execv("/usr/bin/ls",argv);
//    printf("command end...\n");
//    exit(1);
//  }
//  waitpid(-1,NULL,0);
//  printf("wait child process!\n");
//  return 0;
//}

//int main()
//{
//  if(fork()==0){//child
//    execl("/usr/bin/ls","ls","-a","-l","-n",NULL);
//    exit(1);
//  }
//  //parent
//  waitpid(-1,NULL,0);
//  printf("wait success!!\n");
//  return 0;
//}






//int main()
//{
//    printf("I am a process!,pid:%d\n",getpid());
//
//    execl("/usr/bin/lsssss","ls","-a","-l",NULL);
//
//    printf("hahahahahahahaha!\n");
//    printf("hahahahahahahaha!\n");
//    printf("hahahahahahahaha!\n");
//    printf("hahahahahahahaha!\n");
//    printf("hahahahahahahaha!\n");
//    exit(0);
//  return 0;
//}
//


//int main()
//{
//  pid_t id=fork();
//  if(id==0){
//    printf("I am a process!,pid:%d\n",getpid());
//    execl("/usr/bin/ls","ls","-a","-l",NULL);
//    printf("hahahahahahahaha!\n");
//    printf("hahahahahahahaha!\n");
//    printf("hahahahahahahaha!\n");
//    printf("hahahahahahahaha!\n");
//    printf("hahahahahahahaha!\n");
//    exit(0);
//  }
//  while(1){
//    printf("I am a father!\n");
//    sleep(1);
//  }
//  waitpid(id,NULL,0);
//  printf("wait process!!\n");
//  return 0;
//}






//int main()
//{
//  pid_t id=fork();
//  if(id==0){
//    //child
//    int cnt=10;
//    while(cnt){
//      printf("child[%d] running cnt is : %d\n",getpid(),cnt);
//      cnt--;
//      sleep(1);
//    }
//    exit(1);
//  }
//  int status=0;
//  while(1){
//    pid_t ret=waitpid(id,&status,WNOHANG);
//    if(ret==0)
//    {
//      //子进程没有退出，但是waitpid是等待成功的，需要父进程重复进行等待
//      printf("Do father things!\n");
//    }
//    else if(ret>0){
//      //子进程退出了，waitpid也成功了，获取对应的结果
//      printf("father wait:%d ,success,status exit code:%d ,status exit signal:%d\n",ret,(status>>8)&0xff,status&0x7f);
//      break;
//    }
//    else{
//      //ret<0   等待失败
//      perror("waitpid");
//      break;
//    }
//    sleep(1);
//  }
//  return 0;
//
////  int status=0;
////  pid_t ret=waitpid(id,&status,0);
////  if(ret>0)
////  {
////    if(WIFEXITED(status))
////    {
////      printf("exit code: %d\n",WEXITSTATUS(status));
////    }
////    else{
////      printf("error ,get a signal!\n");
////    }
//  }
//
//
//
//

//  if(ret>0){
//    printf("father wait : %d,success,status exit code:%d status exit sign:%d\n",ret,(status>>8)&0xFF,(status)&0x7F);
//  }
//  else{
//    printf("father wait faild!\n");
//  }
  //parent
  //sleep(10);
//``}



//int fun()
//{
//  printf("fun test!!!");
//  return 1;
//}
//
//int main()
//{
//  printf("hello world!!");
//  sleep(3);
//  _exit(12);
//}


//int main()
//{
//  fun();
//  sleep(3);
//  exit(EXIT_SUCCESS);
//}

//int main()
//{
//  fun();
//  for(int i=0;i<140;i++)
//  {
//    printf("%d : %s\n",i,strerror(i));
//  }
//  return 0;
//}
//
//

