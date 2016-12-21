#include<stdio.h>
#include<cstdio>
#include<cstdlib>
struct Point
{
  int x;
  int y;
};
int main()
{
  struct Point p[20];
  FILE *fp=fopen("landscape.txt","r");
  if (!fp)
  {
    perror("file open failed \n");
    exit (10);
  }

  int a,b;
  int index=0;
  for (int i=0; i<20;i++)
  {
    if(fscanf(fp,"%d %d \n",&a,&b)==2)
    {
      p[i].x=a;
      p[i].y=b;
      index++;
    }
    
  }

  for (int i=0; i<index;i++)
  {
    printf("%d %d \n", p[i].x,p[i].y);
  }
}
