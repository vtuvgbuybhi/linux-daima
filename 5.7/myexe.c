#include<stdio.h>


int main()
{
  extern char**environ;
  for(int i=0;environ[i];i++){
    printf("%s",environ[i]);
  }
  printf("my exe runing...done\n ");
  return 0;
}


