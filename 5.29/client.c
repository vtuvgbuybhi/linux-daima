#include"comm.h"
#include<string.h>

int main()
{
  //用不用在创建fifo？？ 我只需要获取即可
  int fd=open(MY_FIFO,O_WRONLY);
  if(fd<0){
    perror("open");
    return 1;
  }
  while(1){
    printf("请输入#");
    fflush(stdout);
    char buffer[64]={0};
    ssize_t s=read(0,buffer,sizeof(buffer)-1);
    if(s>0){
      buffer[s-1]=0;
      printf("%s\n",buffer);

      write(fd,buffer,strlen(buffer));
    }
  }
    
  return 0;
}
