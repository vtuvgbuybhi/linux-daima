#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#define NUM 128
#define CMD 64
int main()
{
  char command[NUM];
  for( ; ; ){
    char* argv[CMD]={NULL};
    //打印提示符
    command[0]=0;//用这种发生可以做到O（1）时间复杂度，清空字符串
    printf("[test_c@myhostname mydir}#");
    fflush(stdout);
    //获取命令字符串
    fgets(command,NUM,stdin);
    command[strlen(command)-1]='\0';//"ls\n\0"

    //解析命令字符串，char*argv[]
    char *sep=" ";
    int i=1;
    argv[0]=strtok(command,sep);
    while(argv[i]=strtok(NULL,sep)){
      i++;
    }
    if(fork()==0){
      execvp(argv[0],argv);
      exit(1);
    }
    
    waitpid(-1,NULL,0);


//    for(int i=0;argv[i];i++){
//      printf("argv[%d]: %s\n",i,argv[i]);
//    };

  } 
  return 0;
}
