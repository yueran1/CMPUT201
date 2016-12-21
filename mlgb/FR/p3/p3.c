#include<stdio.h>
#include"points.h"
#include<cstdio>
#include<cstdlib>

int main()
{
  int e=20;
  Points A(e);
  FILE *fp= fopen("landscape.txt","r");
  if (!fp)
  {
    perror("file opening failed \n");
    exit(10);
  }
  int a,b;
  int index=0;
  for(int i=0;i<20;i++)
  {
    if(fscanf(fp,"%d %d", &a,&b)==2)
    {
      A.x[i]=a;
      A.y[i]=b;
      index++;
    }
  }
  if (fclose(fp))
  {

    perror("file closing failed \n");
    exit(10);
  }
  for (int i=0; i<index;i++)
  {
    printf("%d %d \n", A.x[i],A.y[i]);
  }

  




}
