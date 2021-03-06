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
int indexOfMax(char *A[], const int N)
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
  const int n=10000000;//2k:give you the max size of the input
  char *input= new char[n+1];// make he max size infinity, every time you each the max value, the max value will increase.
  // read standard input, and store in the character array
  // HINT: Keep track of how many characters were read in,
  // and how many newline characters were found.
  int num=0;
  int num_lines=0;
  for(;;)
  {
    int c=getchar();

    if (c==EOF)
    {
      break;
    }
    if(c == '\0')
    {
      printf("0 countered");
      return 2;
    }

    if (c>=n)
    {
      printf("input too long");
      return 1;
    }
    if (c=='\n')//2k: at here we reach the end of argument, so we need to turn to another line now, thats wh num_lines++, and letc='\0' to makre sure argument is right/
    {
      num_lines++;
      c='\0';
    }
    input[num++]= (char)c;//now we assign the input letter into the array(input)
  }
  if (!feof(stdin))// this means our guo cheng cant go to the end, feof(stidin)
                   // will return false
    {
      printf("read error \n");
      return 1;
    }
  if (num == 0 || (num > 0 && input[num-1] != '\0'))// when we reach the last
                                     //line of the whole argument, we need
                                     // give a '\0' to the end
  {
      num_lines++;
      input[num++] = '\0';
  }
  
  // handle errors - "input too long" and "0 encountered"

  assert(num_lines > 0);

  // create an array of pointers, that will point at each line.
  // char** : a double pointer.  But it's quite simple:
  // 'lines' is just an array, where each entry is
  // a (char *): a string.  Right now, the pointers don't point
  // at anything.
  char **lines = new char*[num_lines];
  int linesindex=0;
  int i=0;
  do{  
  
  assert( linesindex < num_lines);
  lines[linesindex]=&input[i];// assign the value of input to the array which
                              //named lines, @ here input is just a pointer,
                              // value of the input is just a address
                              //if we want to get the value of input, we should
                              //use &
                              //TA said use the & make the input i can be jusify
  linesindex++;
  while (input[i]!='\0')
  {
    i++;
  }
  i++;
  }
  while(i<num);
  assert(linesindex==num_lines);
  sort(lines,num_lines);
  // Assign the pointers in the array lines, so that
  // each entry points at a line of input that was read in.
  // We aren't allocating memory here - we're just going to make
  // each pointer point into the big array we allocated at
  // the start of main()

  // sort lines lexicographically ...

  printf( "-----\n" );

  // print lines ...
  for (int i=0; i<n;i++)
  {
    printf("%s \n", lines[i]);
  }
  // cleanup ...
  delete []input;
  delete []lines;
  return 0;
}
