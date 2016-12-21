#include "str.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main()
{
  char *t = clone_string_cpp("foo");
  printf("%s\n", t);    // shall write foo

  free_string_cpp(t); // release memory

  char **tokens; // string array
  int tnum = tokenize(" x  y z ", tokens);

  // tnum = 3
  // tokens[0] : "x"
  // tokens[1] : "y"
  // tokens[2] : "z"
  for (int i = 0; i < tnum; i++)
  {
    printf("%s\n", tokens[i]);
  }
  
  free_tokens(tokens, tnum);
 
  return 0;
}

