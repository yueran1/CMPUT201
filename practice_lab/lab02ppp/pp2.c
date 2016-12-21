#include<stdio.h>

int main()
{
  double n=1.0;
  double sum=0;
  for (int i=0;sum!=(sum+n); i++)
  {
    n=((4.0/(8*i+1)) - (2.0/(8*i+4)) -(1.0/(8*i+5)) - 1.0/(8*i+6));
    for(int c=0; c<i; c++ )
      {
        n =n*(1.0/16);
        printf("%f\n",n);
      }
  sum=sum+n;
    
  }
  printf("%f\n",sum);
}
