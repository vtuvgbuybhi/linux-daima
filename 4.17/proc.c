#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

//int main(int argc,char* argv[],char* env[])
int main()
{
  printf("myenv:%s\n",getenv("myenv"));


//  printf("I am a process pid:%d ,ppid: %d\n",getpid(),getppid());
//  printf("PATH: %s\n",getenv("PATH"));
//  printf("HOME: %s\n",getenv("HOME"));
//  printf("SHELL: %s\n",getenv("SHELL"));
//  for(int i=0;env[i];i++)
//  {
//    printf("%d->%s\n",i,env[i]);
//  }

//  if(argc!=2){
//    printf("Usage: %s -[a][h]\n",argv[0]);
//    return 1;
//  }
//  if(strcmp(argv[1],"-h")==0){
//    printf("hello bit\n");
//  }
//  else if(strcmp(argv[1],"-a")==0){
//    printf("hello all\n");
//  }
//  else{
//    printf("hello world\n");
//  }



//  for(int i=0;i<argc;i++)
//  {
//    printf("argv[%d]->%s\n",i,argv[i]);
//  }


  return 0;
}
