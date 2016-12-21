#include<stdio.h>
#include<string.h>

int main(int argc, char*argv[])
{
  if (argc!=2 ||strlen(argv[1])!=1)
  {
    printf("▄︻┳═一 invailid argument \n");
    return 1;
    }
  // char ch[1000]
    printf("Give me the word you want to check: ");
    //char ch=argv[1];
  
  int count=0;
  char *firstArg = argv[1];
  
  char ch =firstArg[0];
  
   
    
    
    
  for(;;)
  {
    int newchar=getchar();
    if (newchar==EOF)
    {
      break;
    }
    if (newchar == ch)
    {
      ++count;
    }
  }
  printf("The letter you want to count has appeared %d times \n",count);
}
