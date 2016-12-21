#include<stdio.h>

bool is_prime(int a)
{
  if (a==2)
  {
    return true;
  }
  for (int i=2;i<a-1;i++)
  {
    if (a%i==0)
    {
      return false;
    }
  }

  return true;
}

int main()
{
  int c;
  scanf("%d",&c);
  int a=0;
  for (int i=c;;i++)
  {
    if (is_prime(i))
    {
      if (i>c)
      {
        printf("the prime we want to get is %d \n",i);
        break;
      }
    }
  }



}
