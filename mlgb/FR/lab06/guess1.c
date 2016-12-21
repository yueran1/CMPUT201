#include<stdio.h>
#include"guesspass.h"

char guess[5]="    ";

bool add_one(int a)
{
  
  if (guess[a]=='\0')
  {
    if(check(guess))
    {
      printf("%s is the password \n",guess);
      return true;
    }
    else
    {
      printf("%s is not the password \n",guess);
      return false;
    }
  }
  for (int i=0; i<26;i++)
  {
    guess[a]=(char)('a'+i);
    bool res =add_one(a+1);
    if(res==true)
    {
      return true;
    }
  }    
  return false;

  

}

int main()
{
  bool res=add_one(0);
  if (res==false)
  {
    printf("password guessing failed. \n");
  }

  return 0;
}
