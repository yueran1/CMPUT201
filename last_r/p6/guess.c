#include<stdio.h>
#include<string>
#include<iostream>
#include "guesspass.h"
using namespace std;
int main()
{
  //string guess="    ";
  char guess[5];
  guess[4]='\0';
  for (int i1=0; i1<26;i1++)
  {
    guess[0]=(char)('a'+char(i1));
    for(int i2=0; i2<26; i2++)
    {
      guess[1]=(char)('a'+char(i2));
    
      for(int i3=0; i3<26;i3++)
      {
        guess[2]=(char)('a'+char(i2));

        for (int i4=0; i4<26;i4++)
        {
          guess[3]=(char)('a'+char(i3));
          if (check(guess) )
          {
            //cout<<guess<endl;
            printf("%s is the pass word \n",guess);
            return 0;
          }

          else
          {
            //cout<<guess<<endl;
            printf("%s is not the password \n",guess);
          }
        }
      }

     
    }
    
  }
  
}
