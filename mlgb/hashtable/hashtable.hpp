#pragma once
#include "linkedlist.hpp"

// hashtable.hpp
//
// Create a class called HashTable.
// It must support the following functions, which are
// used by spellcheck.cpp
// (it can have more functions as well, if you wish):
//
class HashTable{
  
// Constructor.  Takes an unsigned int newSize, the number of lists
//   to allocate for the hash table.
//
public:
  HashTable(unsigned int newSize);
  
  
  
// Destructor.  Deallocates any memory used by the hash table.
//
  ~HashTable();
// add. Takes a const char * called word: a word to add to the hash table,
//   but check for a duplicate first: we only store unique words.
//   Returns nothing.
  void add(const char* word);
//
// check.  Takes a const char * called word.  Checks to see if the
//   word already exists in the hash table.  If it does, then return 1;
//   if not, then return 0.
  int check(const char* word);
//
// getNumEntries.  Takes nothing, returns an unsigned int.
//   Returns the number of words stored in the hash table.
//
  int getNumEntries();
// getStats.  Takes pointers to two unsigned ints, "shortest" and "longest".
//   Looks through the lists in the hash table, and fills these pointers
//   with the lengths of the smallest and longest lists.
  void getStats(unsigned int *shortest, unsigned int *longest);

private:
  unsigned int tableSize;
  SList *table;
};
  
