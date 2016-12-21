#pragma once

// hashtable.hpp
//
// Create a class called HashTable.
// It must support the following functions, which are
// used by spellcheck.cpp
// (it can have more functions as well, if you wish):
//
// Constructor.  Takes an unsigned int newSize, the number of lists
//   to allocate for the hash table.
//
// Destructor.  Deallocates any memory used by the hash table.
//
// add. Takes a const char * called word: a word to add to the hash table,
//   but check for a duplicate first: we only store unique words.
//   Returns nothing.
//
// check.  Takes a const char * called word.  Checks to see if the
//   word already exists in the hash table.  If it does, then return 1;
//   if not, then return 0.
//
// getNumEntries.  Takes nothing, returns an unsigned int.
//   Returns the number of words stored in the hash table.
//
// getStats.  Takes pointers to two unsigned ints, "shortest" and "longest".
//   Looks through the lists in the hash table, and fills these pointers
//   with the lengths of the smallest and longest lists.
