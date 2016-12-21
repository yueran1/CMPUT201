#include<stdio.h>
#include<iostream>
#include<string>
#include<pthread.h>
#include"guesspass.h"
using namespace std;
int main()
{
  char guess[5];
  char word[27]="abcdefghijklmnopqrstuvwxyz";
  for (int i=0;i<26;i++)
  {
    guess[0]=word[i];
    for (int i=0;i<26;i++)
    {
      guess[1]=word[i];
      for(int i=0;i<26;i++)
      {
        guess[2]=word[i];
        for(int i=0;i<26;i++)
        {
          guess[3]=word[i];
          if(check(guess))
          {
            printf("%s is the password \n",guess);
            return 0;
          }
          else
          {
            printf("%s is not the password \n",guess);
          }
        }
      }
    }
    
  }

}
