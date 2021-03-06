// Read lines from standard input,
// sort them, and print them back out.

#include <stdio.h>
#include <assert.h>
#include <string.h>

// Functions for sorting a C array.
// These do not need to be changed.

// indexOfMax
// Purpose - returns index of the element in A[] that lexicographically
//   comes after all others in A[]
// pre-condition:
//   A is an array that has at least N elements.
//   N > 0
int indexOfMax(const char *A[], const int N)
{
  assert(N > 0);  
  int max_ind = 0;    // current index of max.
  const char *max_val = A[0]; // Pointer to current max string

  for (int i=1; i < N; ++i) {
    // can't use A[i] > max_val because this
    // would compare addresses!
    // instead, need to use strcmp to compare strings
    if (strcmp(A[i], max_val) > 0) {
      // found a bigger element, so update max_val and max_ind
      max_val = A[i]; max_ind = i;
    }
  }
  return max_ind;
}

// swap
// Swaps two char pointers.
// precondition:
//   x and y are references to pointers.
//   (Remember: in order to modify a variable in the calling function,
//     we need to pass in a reference or a pointer to it.  In this case,
//     the variable we are changing happens to itself be a pointer.)
// postconditions:
//   Swaps the pointers x and y
void swap(char * & x, char* & y)
{
  char *tmp = x; 
  x = y; 
y = tmp;
}

// sort
// Performs a selection sort on the array A.
//   In each iteration of the loop, we'll find
//   the line with the highest index, and swap it to the end
//   of the array.
// Precondition:
//   A is an array of strings, of size N.
// Postcondition:
//   Sorts the array lexicographically, from lowest to highest.
void sort(char *A[], const int N)
{
  for (int l=N; l > 1; --l) {
    // swap max. element in A[0..l-1] with A[l-1]
    swap(A[indexOfMax(A, l)], A[l-1]);
  }
}


// The above functions are correct.  You will have to make
// changes to main() below.  

int main()
{
  // Allocate a character array to store the input
  // HINT: How big does the array need to be?  Check the instructions!
  const int n =10000000;
  char *input= new char[n+1];
  
  // read standard input, and store in the character array
  // HINT: Keep track of how many characters were read in,
  // and how many newline characters were found. 
  int num=0;
  int num_line=0;
  for (;;)
  {
    //int cha = scanf("%d",&input_contain); wrong scanf cant read '\0'
    int c= getchar();
    if (num >=n)
    {
      printf("input too long" );
      return 1;
    }
    if (c=='\0')
    {
      printf("0 encountered");
      return 2;
      
    }

    if (c=='\n')
    {
      num_line++;
      c='\0';
    }
    input[num++]=(char) c;
  }
  
  // handle errors - "input too long" and "0 encountered"
  if (!feof(stdin))
  {
    printf("there is some error \n");
    return 1;
  }

  if(num==0 || (num>0 && input[num-1]!= '\0'))
  {
    num_line++;
    input[num++]='\0';
  }
  assert(num_line > 0);

  // create an array of pointers, that will point at each line.
  // char** : a double pointer.  But it's quite simple:
  // 'lines' is just an array, where each entry is
  // a (char *): a string.  Right now, the pointers don't point
  // at anything.
  char **lines = new char*[num_line];
  int lineindex=0;
  int i=0;
  do
  {
    assert(lineindex<num_line);
    lines[lineindex]=&input[i];
    lineindex++;
    while (input[i]!='\0')
    {
      i++;
    }
    i++;
  }while(i<n);//???????
  // Assign the pointers in the array lines, so that 
  assert(lineindex==num_line);
  sort(lines,num_line);
  
  

// each entry points at a line of input that was read in.
  // We aren't allocating memory here - we're just going to make
  // each pointer point into the big array we allocated at
  // the start of main()
  
  // sort lines lexicographically ...

  printf( "-----\n" );
  for (int i=0; i<num_line; i++)
  {
    printf("%s \n",lines[i]);
  }

  // print lines ...

  // cleanup ...
  delete [] lines;
  delete [] input;
  return 0;
}
