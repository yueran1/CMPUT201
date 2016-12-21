#include<stdio.h>
#include"points.h"
#include<cstdio>
#include<cstdlib>
int main()

{
  FILE *fp=fopen("landscape.txt","r");
  if(!fp)
  {
    perror("file open failed \n");
    exit(10);
  }

  Points p(20);
  int a,b;
  int index;
  for(int i=0;i<20;i++)
  {
    if (fscanf(fp,"%d %d \n",&a,&b)==2)// Number of receiving arguments
      //successfully assigned, or EOF if read failure occurs before the first
      //receiving argument was assigned. 
    {
      p.x[i]=a;
      p.y[i]=b;
      index++;
    }
  }

  for (int i=0;i<index;i++)
  {
    printf("%d %d \n",p.x[i],p.y[i]);
  }
}
