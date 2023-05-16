#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
  int fd=open("./log.txt",O_WRONLY|O_CREAT,0644);
  int fd1=open("./log.txt1",O_WRONLY|O_CREAT,0644);
  int fd2=open("./log.txt2",O_WRONLY|O_CREAT,0644);
  int fd3=open("./log.txt3",O_WRONLY|O_CREAT,0644);
  if(fd<0){
    printf("open error\n");
  }
  printf("fd:%d\n",fd);
  printf("fd1:%d\n",fd1);
  printf("fd2:%d\n",fd2);
  printf("fd3:%d\n",fd3);
  close(fd);
  return 0;
}




//int main()
//{
//  const char*msg="you can see me!\n";
//  fputs(msg,stderr);
//  return 0;
//}

//int main()
//{
////  FILE *fp=fopen("./log.txt","w");
//  FILE *fp=fopen("./log.txt","r");
////  FILE *fp=fopen("./log.txt","a");
//  if(fp==NULL){
//    perror("fopen");
//    return 1;
//  }
//  
//  char buffer[64];
//  while(fgets(buffer,sizeof(buffer),fp)){
//    printf("%s",buffer);
//  }
//
//  if(!feof(fp)){
//    printf("fgets quit not normal!\n");
//  }
//  else{
//    printf("fgets quit normal!\n");
//  }
//
//
////  int cnt=5;
////  while(cnt--){
////    const char* msg="hello cdc\n";
////    fputs(msg,fp); 
////  }
//
//  fclose(fp);
//  return 0;
//}

