#include<stdio.h>

int main()
{
  int x=9;
  int count=0;
  for(int i=1; i<x; i++)
  {
    if (i!=1 && i!=2 && i!=3 && i!=5)
    {
      if (x%i==0)
      {
        count+=1;
      }
    }
  }
  if (count==0)
  {
    printf("%d is ugly \n",x);
  }
  else
  {
    printf("is not ugly\n");
  }
  printf("%d \n",count);
}
