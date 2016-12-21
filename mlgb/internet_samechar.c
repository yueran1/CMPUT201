#include <stdio.h>

/* count characters and input using for */
int main()
{
  printf("give me the letter you want to check: ");
  long nc;
  int count=0;
  char ch='o';
  for (nc = 0; ; ++nc)
    
  {  
    int newc=getchar();
    if (newc==EOF)
    {
      break;
    }
    if (newc==ch)
    {
      count++;
    }
  }
  printf("there is %d times letter comes out \n",count);
}
