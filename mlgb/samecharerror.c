#include<stdio.h>
int main()
{
  char ch[1000];
  printf("Give me the letter you want to count: \n");
  char newchar=scanf("%s",ch);
  int count=0;
  for(;;)
  {
    if (newchar==EOF)
    {
      break;
    }
    if (newchar==ch)
    {
      count++;
    }
  }
  printf("The letter you want to count has appeared %d times \n",count);
}
