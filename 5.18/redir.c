#include<stdio.h>
#include<unistd.h>
#include<string.h>


int main()
{
  //系统接口
  const char *msg1="hello 标准输出\n";
  write(1,msg1,strlen(msg1));


  //C语言调用接口
  printf("hello printf\n");
  fprintf(stdout,"hello fprintf\n");
  fputs("hello fputs\n",stdout);

  fflush(stdout);

  fork();

  return 0;
}














//int main()
//{
//  //系统接口
//  const char *msg1="hello 标准输出\n";
//  write(1,msg1,strlen(msg1));
//
//  const char *msg2="hello 标准错误\n";
//  write(2,msg2,strlen(msg2));
//
//  //C语言调用接口
//  printf("hello printf\n");
//  fprintf(stdout,"hello fprintf\n");
//   
//  close(1);
//
//  return 0;
//}

