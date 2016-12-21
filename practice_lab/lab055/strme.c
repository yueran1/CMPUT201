#include "str.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


// creates a copy of a string using new and returns a pointer to it,
char *clone_string_cpp(const char *s)
{
  char *p= new char[strlen(s)+1];
  strcpy(p,s);
  return p;
}

// frees strings created by clone_string_cpp
void free_string_cpp(const char *s)
{
  delete [] s;
}

// creates a copy of a string using malloc and returns a pointer to it,
char *clone_string_c(const char *s)
{
  char *p = (char*)malloc(strlen(s)+1);
  strcpy(p,s);
  return p;
  
}

// frees strings created by clone_string_c 
void free_string_c(const char *s)
{
  free((char*)s);
}

static int read_word(const char *&s)
{
  while(*s=='' || *s=='\n' || *s=='\t')
  {
    s++;
  }
  char *t=s;
  // tracking until reach end of the string or white space 
  while (*s!='' && *s!='\n' && *s!='\t' && *s!='\0')
  {
    s++;
  }
  return (int)(s-t);
}

// Tokenize string s into words that consist of
// characters != ' ', '\n', '\t' (white spaces)
// White space is skipped before reading any word.
// The number of tokens and the starting address of
// an array containing them are returned

// Examples:
//
// s                   tokens      (return value)
//
// "abc  def "         "abc" "def" (2)
// "  x \t  y \n z "   "x" "y" "z" (3)
// "  "                            (0)
int tokenize(const char *s, char ** & tokens)
{

  // Step 1: count number of tokens
  int count=0;
  int our_length;
  do
  {
    our_length=read_word(s);
    if (our_length)
    {
      count++;
    }
  } while(our_length);

  
  // Step 2: allocate token array
  tokens= new char*[count];
 
  

  
  // Step 3: create tokens

  int index=0;
  do
  {
    our_length=read_word(s);
    if (our_length)
    {
      tokens[index]=new char[stren(s)+1];
      //tokens[index]=our_length;
      strncpy(tokens[index],s-our_length, our_length );

      tokens[index][our_lenght]='\0';
      index++
    }
  }while(our_length);

  // Step 4: return number of tokens
  return count;

}


// free token array created by tokenize, tnum = number of tokens
// free token array created by tokenize, tnum = number of tokens

void free_tokens(char ** tokens, int tnum)
{
  for(int i=0; i<tnum; i++)
  {
    // first free all tokens
    delete [] tokens[i];
    
  }
  // then free token array
  delete [] tokens;
}

