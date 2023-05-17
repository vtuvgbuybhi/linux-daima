#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


int main()
{
  int fd=open("./log.txt",O_WRONLY | O_TRUNC);
  if(fd<0){
    perror("open");
    return 1;
  }
  dup2(fd,0);

  printf("hello world\n");
  fprintf(stdout,"hello fprintf\n");
  fputs("hello fputs\n",stdout);
  return 0;
}






//int main()
//{
//  printf("stdin -> %d\n",stdin->_fileno);
//  printf("stdout ->%d\n",stdout->_fileno);
//  printf("stderr ->%d\n",stderr->_fileno);
//  return 0;
//}
//int main()
//{
//  close(0);
//  int fd=open("./log.txt",O_RDONLY);
//  printf("fd : %d\n",fd);
//  char line[128];
//  while(fgets(line,sizeof(line)-1,stdin)){
//    printf("%s",line);
//  }
//
//  return 0;
//}
//


//int main()
//{
//  close(1);
//  int fd=open("./log.txt",O_CREAT | O_WRONLY | O_APPEND,0644);
//  if(fd<0){
//    printf("error open");
//    return 1;
//  }
//  printf("hello world\n");
//  printf("hello world\n");
//  printf("hello world\n");
//  printf("hello world\n");
//  printf("hello world\n");
//  printf("hello world\n");
//
//  return 0;
//}





//int main()
//{
//  char buff[64];
//  size_t s=read(0,buff,sizeof(buff));
//  buff[s-1]=0;
//  printf("echo#  %s\n",buff);
//  return 0;
//}

//int main()
//{
//  const char *msg="hello cdc!\n";
//  write(2,msg,strlen(msg));
//  write(2,msg,strlen(msg));
//  write(2,msg,strlen(msg));
//  write(2,msg,strlen(msg));
//
//  return 0;
//}


//int main()
//{
//  int fd0=open("./log.txt0",O_CREAT | O_WRONLY,0644);
//  int fd1=open("./log.txt1",O_CREAT | O_WRONLY,0644);
//  int fd2=open("./log.txt2",O_CREAT | O_WRONLY,0644);
//  int fd3=open("./log.txt3",O_CREAT | O_WRONLY,0644);
//  int fd4=open("./log.txt4",O_CREAT | O_WRONLY,0644);
//  
//  printf("%d %d %d %d %d \n",fd0,fd1,fd2,fd3,fd4);
//
//  close(fd0);
//  close(fd1);
//  close(fd2);
//  close(fd3);
//  close(fd4);
//
//  return 0;
//}

//int main()
//{
//  int fd=open("./log.txt",O_RDONLY);
//  if(fd<0){
//    perror("open");
//    return 1;
//  }
//  char buffer[1024];
//  size_t s=read(fd,buffer,sizeof(buffer)-1);
//  if(s>0){
//    buffer[s]=0;
//    printf("%s",buffer);
//  }
//
//  close(fd);
//  return 0;
//}





//int main()
//{
//  int fd=open("./log.txt",O_CREAT | O_WRONLY,0644);
//  if(fd<0){
//    printf("open error");
//    return 1;
//  }
//  
//  const char *msg="hello cdc!!\n"; 
//  int cnt=5;
//  while(cnt--){
//    write(fd,msg,strlen(msg));
//  }
//
//  close(fd);
//  return 0;
//}















