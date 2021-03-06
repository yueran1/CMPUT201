/*
    == Your Name == : Sun Yue RAn
   [3  marks ] Coding Style
   [2  marks ] Correct Compilation with no warnings
   [10 marks ] Functionality 
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



void reduce(unsigned int A[], unsigned int n)
{
  assert(n>0);
  unsigned int smallest=A[0];
  for (unsigned int i=1;i<n;i++)
  {
    if (A[i]>A[0])
    {
      smallest=A[i];
    }
  }

  for (unsigned int i=0;i<n;i++)
  {
    A[i]=A[i]-smallest;
  }

// this for loop is for debug
 for (unsigned int i=0;i<n;i++)
  {
    printf("%d \n",A[i]);
    }
  
  
}



int main()
{
  FILE *fp=fopen("p1_input","r");
  if (!fp)
  {
    perror("opening the file failed \n");
    exit(10);
  }
  unsigned int x;
  unsigned int size;

  
  if(fread(&x,sizeof(x),1,fp)==1){
    size=x;
  }
  else
  {
    perror("reading the file failed \n");
    exit(10);
  }

  unsigned int *A= new unsigned int [size];
  for (unsigned int i=0;i<size;i++)
  {
    A[i]=rand()%100;
  }

// this for loop is for debug
for (unsigned int i=0;i<size;i++)
  {
    printf("%d \n",A[i]);
    }

  reduce(A,size);

  if (fclose(fp))
  {
    perror("close the file failed \n");
    exit(10);
  }
   printf("size is %d \n",size);
   delete [] A;
}


