#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int g_val=100;
int main()
{
  if(fork()==0)
  {
    //child
    int cnt=5;
    while(cnt)
    {
      printf("I am child , time: %d  g_val= %d ,&g_val=%p\n",cnt,g_val,&g_val);
      cnt--;
      sleep(1);
      if(cnt==3)
      {
         printf("###############更该数据##################\n");
         g_val=200;
         printf("#############更该数据完成################\n");
      } 
    }
   }
  else{
    //parent
    while(1)
    {
      printf("I am father ,  g_val= %d ,&g_val=%p\n",g_val,&g_val);
      sleep(1);
    }
  }
  return 0;
}








//int main()
//{
//  printf("code addr : %p\n",main);
//  
//  const char *s="hello world";
//  printf("string rdonly addr: %p\n",s);
//
//  printf("uninit addr: %p\n",&g_unval);
//  printf("init addr: %p\n",&g_val);
//
//  char *heap=(char*)malloc(10);
//  printf("heap addr: %p\n",heap);
//
//  printf("stack s addr: %p\n",&s);
//  printf("stack heap addr: %p\n",&heap);
//
//  int a=10;
//  int b=30;
//  printf("stack a addr: %p\n",&a);
//  printf("stack b addr: %p\n",&b);

//  return 0;
//}

