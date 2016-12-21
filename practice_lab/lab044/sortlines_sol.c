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
int indexOfMax( char *A[], int N)
{
  assert(N > 0);  
  int max_ind = 0;    // current index of max.
  const char *max_val = A[0]; // current maximum value

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
// Swaps two char pointers
// precondition:
//   x and y are references to pointers.
//   (Remember: in order to modify a variable in the calling function,
//     we need to pass in a reference or a pointer to it.  In this case,
//     the variable we are changing happens to itself be a pointer.)
// postconditions:
//   Swaps the pointers x and y
void swap(char * & x, char * & y)
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
void sort(char *A[], int N)
{
  for (int l=N; l > 1; --l) {
    // swap max. element in A[0..l-1] with A[l-1]
    swap( A[ indexOfMax( A, l ) ], A[ l-1 ] );
  }
}


// The above functions are correct.  You will have to make
// changes to main() below.  

int main()
{
  const int N = 10000000; // max. length

  // allocate large enough array
  // leave room for added '\n' at end  
  char *input = new char[N+1]; 

  // read all characters into array
  int num = 0;
  int num_lines = 0;
  
  for (;;) {
    int c = getchar();
    // char b=c;
    if (c == EOF) {
      break;
    }

    if (c == '\0') {
      printf("0 encountered\n");
      return 2;
    }

    if (num >= N) {
      printf("input too long\n");
      return 1;
    }

    // convert '\n' to '\0'
    if (c == '\n') {
      num_lines++;
      c = '\0';
    }
    
    input[num++] =(char) c;
  }

  if (!feof(stdin)) {
    printf("read error\n");
    return 1;
  }

  // add '\0' if last line was not terminated by '\n'
  if (num == 0 || (num > 0 && input[num-1] != '\0')) {
    num_lines++;
    input[num++] = '\0';
  }

  assert(num_lines > 0);

  // create an array of pointers pointing
  // to each line
  char **lines = new char*[num_lines];
  int lineIndex = 0;

  int i = 0;
  do {
    // Assign the next line
    assert( lineIndex < num_lines );
    lines[ lineIndex ] = &input[ i ];
    lineIndex++;

    // find end of the string / start of the next one
    while ( input[i] != '\0' ) {
      i++;
    }
    // i is now the index of the null character: the end of the string.
    // Advance it once more, so that it points at the start of 
    // the next string.
    i++;
    // Keep looping while i is within the number of characters
    // of input that we read. 
  } while ( i < num );

  // printf("%d %d\n", num_lines, index);

  // Make sure that we assigned all of the lines that we read.
  assert( lineIndex == num_lines );

  // sort lines lexicographically
  sort(lines, num_lines);

  printf( "-----\n" );

  // print them
  for (int i=0; i < num_lines; i++) {
    printf("%s\n", lines[i]);
  }

  delete [] lines;
  delete [] input;
  return 0;
}
