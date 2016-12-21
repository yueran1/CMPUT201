#include "str.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


// creates a copy of a string using new and returns a pointer to it,
char *clone_string_cpp(const char *s)
{
  char * cs=new char [strlen(s)+1]; //+1 one for string erminator
  strcpy(cs,s);
  return cs;
}

// frees strings created by clone_string_cpp
void free_string_cpp(const char *s)
{
  delete [] s;
}

// creates a copy of a string using malloc and returns a pointer to it,
char *clone_string_c(const char *s)
{
  char *cs= (char*)malloc(srlen(s)+1);
  strcpy(cs,s);
  return cs;
}

// frees strings created by clone_string_c 
void free_string_c(const char *s)
{
  free((char*)s);
}

//help function
static int read_word(const char * & s)
{
  // skip white space
  while(*s =='' || *s=='\t' || *s =='\n')
  {
    s++;
  }
  
  const char*t =s;
  // read until reaching end of string or white space
  while (*s!= '\0' && *s!= '' && *s!='\t' && *s != '\n')
  {
    s++;
  }
  //number of characters in word
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
  int tlen;
  do
  {
    tlen=read_word(t);
    if (tlen)
    {
      count++;
    }
  }while(tlen);
  // Step 2: allocate token array

  tokens=new char*[count];
  
  // Step 3: create tokens
  int index=0;

  do
  {
    tlen=read_words(s);
    if (tlen)
    {
      //allocae memor for tokens[index]
      tokens[index]=new char[tlen+1];

      //copy len characters from s (which is a word) to tokens[index]
      trncpy(tokens[index], s-tlen, tlen);

      // erminate word
      tokens[index][tlen]='\0';
      index++;
    }
  }while(tlen);


  // Step 4: return number of tokens
  return count;

}


// free token array created by tokenize, tnum = number of tokens
void free_tokens(char ** tokens, int tnum)
{
  for (int i=0; i<tnum; ++i)
  {
    delete [] tokens[i];
    
  }
  // then free token array
  delete [] tokens;
}

