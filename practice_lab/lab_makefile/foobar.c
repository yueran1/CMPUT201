# include "foo.h"
# include "bar.h"
# include<stdio.h>

int main()
{
  int x=foo(0);
  int y= bar(FOO_MAX);
  printf("value of x is %d \n",x);
  printf("value of y is %d \n",y);
  return 0;
}
