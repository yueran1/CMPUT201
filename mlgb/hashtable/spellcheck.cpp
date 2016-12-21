// spellcheck.cpp
// A simple spell-checking program,
// powered by a hash table.
// Mike Johanson, October 30, 2014

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <sys/time.h>

#include "hashtable.hpp"
#include "util.hpp"

// 'words' is a dictionary file: one word on each line.
// It's at this path on Mac OSX and the lab computers and other
// UNIX systems.
//
// Note that the words file on a Mac appears to not include several
// common word suffixes: for example, it includes "jump" but 
// not "jumped" or "jumps", while these words are in the lab
// computer's words file.  So, on a Mac, you may get a few false
// positives.
//
// For testing, you can try making a replacement file in your own 
// filespace, fill it with 4-5 words (one per line), and change
// dictionaryPath to the name of your replacement file.
// That may be easier to trace than the 99,171 words in the lab
// computer's words file.
const char *dictionaryPath = "/usr/share/dict/words";


int main( const int argc, const char *argv[] )
{
  if( argc != 2 ) {
    printf( "Usage: ./spellcheck <file>\n" );
    return 1;
  }

  // Create hash table, fill it with dictionary words.
  // The constructor parameter is the number of entries 
  // in the hash table. Any number > 0 will do, including 1,
  // which may be useful for testing (but may take ~20 seconds).
  // Bigger is faster, and uses a tiny amount more memory, 
  // but this overhead is very small compared to memory needed to 
  // store the dictionary words.
  // For debugging, you may want to use a smaller number, such as
  // 1 or 5.  
  //
  // To get an even distribution of words across the lists in
  // the hash table, we want the number of entries (29989 here)
  // and the hashing constant (31, in util.cpp) to be
  // co-prime (no factors > 1 in common).  
  // Here, we've chosen two prime numbers.
  HashTable ht( 29989 );

  printf("Loading dictionary file [%s]...\n", dictionaryPath );

  // These lines track the time that we start loading.
  // Used to measure our speed later on.
  struct timeval dictStart;
  gettimeofday( &dictStart, NULL );

  // Open the dictionary file
  FILE *stream = fopen( dictionaryPath, "r" );
  if( stream == NULL ) {
    printf( "Couldn't open dictionary file [%s]\n", dictionaryPath );
    return 1;
  }

  // Add words
  char buffer[ 1000 ];
  while( fgets( buffer, 1000, stream ) != NULL ) {
    // process the string - convert to lowercase, remove
    // punctuation.
    processString( buffer );
    ht.add( buffer );
  }
  
  // Close dictionary
  fclose( stream );

  // Now that we're done, measure how much time it took.
  struct timeval dictEnd;
  gettimeofday( &dictEnd, NULL );
  double dictLoadTime = (double)(dictEnd.tv_sec - dictStart.tv_sec) + (double)(dictEnd.tv_usec - dictStart.tv_usec) / 1000000.0;

  // Print stats about the dictionary we loaded.
  printf("Dictionary loaded (%u words).  Load took %lf seconds.\n", ht.getNumEntries(), dictLoadTime );
  // Find the lengths of the longest and shortest list in the hash table.
  // For performance, we want the words to be fairly evenly spread out.
  // But with randomness, we will expect a few long and short ones.
  unsigned int shortest, longest;
  ht.getStats( &shortest, &longest );
  printf("Shortest list length: %u.  Longest list length: %u\n", shortest, longest );


  // Now that the dictionary is loaded, we can start spellchecking
  // the input file.

  printf("\nSpellchecking file [%s]\n", argv[ 1 ] );

  struct timeval spellStart;
  gettimeofday( &spellStart, NULL );

  unsigned int numWords = 0;
  unsigned int numTypos = 0;
  char copy[ 1000 ];
  // Open input file, check contents
  stream = fopen( argv[ 1 ], "r" );
  while( fscanf( stream, "%1000s", buffer ) != EOF ) {
    // Make a copy of the word before we process it (converting
    // to lowercase, removing punctuation)
    strncpy( copy, buffer, 1000 );
    processString( buffer );
    // After processing, is the word non-empty?
    // This avoids looking up 'words' that were only punctuation marks
    if( buffer[ 0 ] != '\0') {
      numWords++;
      if( ht.check( buffer ) == 0 ) {
	// Word was not found in the hash table!
	printf("  [%s], originally [%s]\n", buffer, copy );
	numTypos++;
      }
    }
  }
  fclose( stream );
  
  // Get stats about how long it took to check the document
  struct timeval spellEnd;
  gettimeofday( &spellEnd, NULL );
  double spellTime = (double)(spellEnd.tv_sec - spellStart.tv_sec) + (double)(spellEnd.tv_usec - spellStart.tv_usec) / 1000000.0;
  
  // Print final stats about the document
  printf("Spellcheck complete: %u words and %u errors.  Took %lf seconds\n", numWords, numTypos, spellTime );

  return 0;
}
