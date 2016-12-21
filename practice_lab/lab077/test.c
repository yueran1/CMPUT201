#include<stdio.h>

int main()
{
  int a =100;
  for (int i=7 ; i>=0; i--)
  {
    
  
    if (a%2==0)
    {
      printf("0");
      
    }
    else
    {
      printf("1");
    }
    a=a/2;
    
  }
  printf("\n");
}
