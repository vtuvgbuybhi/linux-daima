#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
  int pipefd[2]={0};

  if(pipe(pipefd)!=0){
    perror("pipe error\n");
    return 1;
  }
  printf("pipefd[0] : %d\n",pipefd[0]);
  printf("pipefd[1] : %d\n",pipefd[1]);

  if(fork()==0){//子进程
    close(pipefd[0]);
    const char* msg="hello 比特\n";
    int count=0;
    while(1){
      write(pipefd[1],msg,strlen(msg));
    }
    exit(0);
  }
  //父进程
  close(pipefd[1]);
  while(1){
    sleep(10);
    char c[64]={0};
    size_t s=read(pipefd[0],c,sizeof(c));
    if(s>0){
      c[s]=0;
      printf("father take : %s\n",c);
    } 
    else if(s==0){
      printf("writer quit\n");
      break;
    }
    else{
      break;
    }
    break;
  }
  close(pipefd[0]);
  int status=0;
  waitpid(-1,&status,0);
  printf("exit code:%d\n",(status>>8)&0xff);
  printf("exit signal : %d\n",status&0x7f);
  return 0;
}




//int main()
//{
//  int pipefd[2]={0};
//
//  if(pipe(pipefd)!=0){
//    perror("pipe error\n");
//    return 1;
//  }
//  printf("pipefd[0] : %d\n",pipefd[0]);
//  printf("pipefd[1] : %d\n",pipefd[1]);
//
//  if(fork()==0){//子进程
//    close(pipefd[0]);
//    const char* msg="hello 比特\n";
//    int count=0;
//    while(1){
//      write(pipefd[1],msg,strlen(msg));
//      sleep(10);
////      write(pipefd[1],"a",1);
////      count++;
////      printf("count : %d\n",count);
//    }
//    exit(0);
//  }
//  //父进程
//  close(pipefd[1]);
//  while(1){
////    sleep(10);
//    char c[64]={0};
//    size_t s=read(pipefd[0],c,sizeof(c));
//    c[s]=0;
//    printf("father take : %c\n",c[0]);
////    char buffer[64]={0};
////    size_t s=read(pipefd[0],buffer,sizeof(buffer)-1);
////    if(s==0){
////      printf("child quie...\n");
////       break;
////    }
////    else if(s>0){
////      buffer[s]=0;
////      printf("child say to father : %s\n",buffer);
////    }
////    else{
////      printf("child error...\n");
////      break;
////    }
//  }
//  return 0;
//}











//int main()
//{
//  int pipefd[2]={0};
//
//  if(pipe(pipefd)!=0){
//    perror("pipe error\n");
//    return 1;
//  }
//  printf("pipefd[0] : %d\n",pipefd[0]);
//  printf("pipefd[1] : %d\n",pipefd[1]);
//
//  if(fork()==0){//子进程
//    close(pipefd[0]);
//    const char* msg="hello 比特\n";
//    while(1){
//      write(pipefd[1],msg,strlen(msg));
//     // sleep(1);
//    }
//    exit(0);
//  }
//  //父进程
//  close(pipefd[1]);
//  while(1){
//    sleep(1);
//    char buffer[64]={0};
//    size_t s=read(pipefd[0],buffer,sizeof(buffer)-1);
//    if(s==0){
//      printf("child quie...\n");
//       break;
//    }
//    else if(s>0){
//      buffer[s]=0;
//      printf("child say to father : %s\n",buffer);
//    }
//    else{
//      printf("child error...\n");
//      break;
//    }
//  }
//  return 0;
//}
//
//
