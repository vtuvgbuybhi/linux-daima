#include<stdio.h>
#include<unistd.h>

int main(int argc,char*argv[])
{
  for(int i=0;i<argc;i++)
  {
    printf("argv[%d] ->%s\n ",i,argv[i]);
  }

//    int con=5;
//    while(con)
//    {
//      printf("hello world\n");
//      sleep(1);
//      con--;
//    }


//  while(1)
//  {
//    printf("I am process ,pid: %d ,ppid: %d\n",getpid(),getppid());
//    sleep(1);
//  }
  return 0;
}
