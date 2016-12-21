/*
    == Your Name == : Sun Yue RAn
   [3  marks ] Coding Style
   [2  marks ] Correct Compilation with no warnings
   [10 marks ] Functionality 
 */


#include <stdio.h>
#include <pthread.h>
#include "p3pass.h"
#include <stdlib.h>
#include <string>

using namespace std;


struct Job
{
  
  long *p;
  int start;
  int end;
  long password[6];
  
  
  
};

long *password(void *data)
{
  Job *job = (Job *) data;
  long *A=job->p;
  
  for (int i=job->start; i<job->end;i++)
  {
    for(int a=0;a<9;a++)
    {
      if (check(a))
      {
        A[i]=a;
        job->password[i]=A[i];
        
      }
    }
  }
}

int main() {

  int guess[7];
  //guess[7]='0';
  //char word[27]="abcdefghijklmnopqrstuvwxyz";
  Job jobs[7];
  pthread_t threads[4];

  int items=6;
  int seprate=items/4;
  int mod=items%4;
  int start1=0;
  for (int i=0; i<4;i++)
  {
    jobs[i].start=start1;
    jobs[i].end=start1+seprate;
  }
  if (mod>0)
  {
    jobs[i].end++;
    mod--;
  }
  start1=jobs[i].end;
  jobs[i].p=guess;

  pthread_create(&threads[i], 0, password, &jobs[i]);

  for(int i=0; i<4;i++)
  {
    pthread_join(threads[i],0);
  }
  
  
  for (int i=0;i<4;i++)
  {
    fprintf("%d",jobs[i].password);
  }

  //return result;
  

}





