#pragma once

// some string functions ...

// creates a copy of a string using new and returns a pointer to it,
char *clone_string_cpp(const char *s);

// frees strings created by clone_string_cpp
void free_string_cpp(const char *s);

// creates a copy of a string using malloc and returns a pointer to it,
char *clone_string_c(const char *s);

// frees strings created by clone_string_c 
void free_string_c(const char *s);


// Tokenize string s into words which consist of
// characters != ' ', '\n', '\t' (white spaces)
// White space is skipped before reading words.
// The number of tokens and the starting address of
// an array containing them are returned
//
// Examples:
//
// s                   tokens
//
// "abc  def "         "abc" "def" (2)
// "  x \t  y \n z "   "x" "y" "z" (3)
// "  "                            (0)
int tokenize(const char *s, char ** & tokens);


// free token array created by tokenize, tnum = number of tokens
void free_tokens(char ** tokens, int tnum);
