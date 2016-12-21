#include <stdio.h>

typedef unsigned char byte;

// Prints a in hexadecimal.
void byte_print_hex( const byte a ){
  printf("%02x", a);
}

// Prints a in binary.
void byte_print_binary( const byte a ){
  // There are many ways to do this - here is one option:
  
  // loop through the 8 bits
  for (int i = 7; i >=0; i--)
  {
    // print one bit
    printf("%d", (a >> i) & 1);
  }
}

// Count the number of 1-bits (bits in a that is 1).
int byte_count_ones( const byte a ){
  int count = 0;
  int x = a;
  
  while (x) {    
    // x & 1 gives you the least-order bit of x
    if ((x & 1) == 1)
    {
      count++;
    }
    x = (x >> 1);
  }
  return count;
}

// Performs "bit-wise and" operation
void byte_and( byte *a, const byte x, const byte y ){
  *a = x & y;
}

// Rotates a bit-wise to the right
void byte_rotate_right( byte *a ){
  // There are many ways to do this - here is one option
  // When shifting right on an unsigned variable,
  // the high-order bits are filled with 0s

  // (*a >> 1) shifts the 7 bits back one position
  // (*a << 7) shifts the least-order bit up to the first position
  *a = (byte)((*a >> 1) | (*a << 7));
}

int main()
{
  byte a = 100;
  printf("Testing with a=%d\n", a );
  printf("  hex: " ); // expecting 64, if a=100
  byte_print_hex(a);  
  printf("\n");
  printf("  binary: "); // expecting 01100100, if a=100
  byte_print_binary(a);  
  printf("\n");

  int count = byte_count_ones(a);
  printf("  Number of 1-bits: %d\n", count); // expecting 3, if a=100


  byte x = 101, y = 102;
  printf("\nTesting byte_and:\n");
  printf("x=       %9d, in binary: ", x);
  byte_print_binary(x);
  printf("\n");
  printf("y=       %9d, in binary: ", y);
  byte_print_binary(y);
  printf("\n");
  byte z;
  byte_and(&z, x, y );
  printf("z=x&y is %9d, in binary: ", z);
  byte_print_binary(z);
  printf("\n");

  a = 230;
  printf("\nTesting rotation.  %9d in binary is:\n", a );
  byte_print_binary(a);
  printf(", rotated right one bit is:\n" );
  byte_rotate_right( &a );
  byte_print_binary( a );
  printf("\n");
  
  return 0;
}
