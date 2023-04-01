#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define NUM 100
int main()
{

  char bar[NUM+1];
  int i=0;
  memset(bar,'\0',sizeof(bar));

  const char* lable="|/-\\";

  while(i<=100)
  {
    printf("[%-100s][%d%%] %c\r",bar,i,lable[i%4]);
    fflush(stdout);
    bar[i]='#';
    i++;
    usleep(50000);
  }
  printf("\n");
  return 0;
}
