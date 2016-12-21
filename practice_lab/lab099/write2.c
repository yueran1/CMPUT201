#include<cstdio>
#include<cstdlib>
#include<stdio.h>
using namespace std;
int main(int argc, char*argv[])
{
  // int N=10000;
  FILE *fp=fopen("test1","w");
  
  if (!fp)
  {
    perror("encountered fopen error");exit(10);
  }

  
  {
    for (int i=1;i<argc;i++){  
    if(fprintf(fp,"%s ",argv[i])<0)
    {
      perror("encountered fprintf error");exit(10);
    }
    }
  }

  if (fclose(fp))
  {
    perror("encountered fclose error"),exit(10);
  }
  return 0;
}
