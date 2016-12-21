#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

  if (argc != 2 || strlen(argv[1]) != 1 )
  {
    printf("Invalid arguments\n");
    return 1;
  }

  //char A[1000+1];    // if we know the maximum input size we can declare this
 
  int size = 10;
  char *A = new char[size];  // A uses dynamic memory to store the input string
 
  int location = 0;          // current index location of A
 
  char *firstArg = argv[1];  // argument from command line
  char c = firstArg[0];      // first character of argument

  int count = 0;
 
  // for(;;)
  while (true)
  {
    int newChar = getchar();

    if (newChar == EOF)
    {
      break;
    }

    // this part is only needed when we don't know the max size of input
    if (location == size-1)   // as soon as we reach the max size of array
    {
      // allocate more memory
      size = size + 10;
      char*B = new char[size];
      A[location] = '\0';
      strcpy(B, A);
      delete [] A;
      A = B;
    }

    
    A[location] = (char) newChar;
    location++;
    
    if (newChar == c)
    {
      count++;
    }
  }


  A[location] = '\0';  // make sure the string ends with the end-marker
 
  printf("We have seen the character %d times.\n", count);
  printf("The input string is: %s\n", A);

  delete [] A;
  return 0;
}
