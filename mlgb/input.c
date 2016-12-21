#include<stdio.h>
char main()
{
  char miles;
  printf("Enter distance in miles: ");
  int c=scanf ("%c",&miles);
  while(true)
  {

    if (c==EOF)
    {
      break;
    }
    
    if (c)
    {
      printf("%s \n",c);
    }
    
  }
}
