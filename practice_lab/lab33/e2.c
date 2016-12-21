#include<stdio.h>
#include<assert.h>
int smallest(const int A[], int n)
{
  assert (A>0);
  int index=0;
  int min=A[0];
  int temple=0;
  for(;index<n; index++)
  {
    if(min>A[index])
    {
      min=A[index];
      temple=index;
    }
  }
  return temple;
}


int main()
{
  int A[] =  {45, 24, 65, 10, 8, 50};
  int n = 6;
  printf("The index of smallest number is %d \n ",smallest(A, n) );
}
