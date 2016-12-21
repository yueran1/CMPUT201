#include <stdio.h>

typedef unsigned char byte;

// Prints a in hexadecimal.
void byte_print_hex( const byte a ){
  printf("The number in hex is %x \n", a);
}

// Prints a in binary, from the high-order bits to the low-order bits
void byte_print_binary(const byte a ){
   int b=a;
   for (int i=7; i>=0;i--)
  {
   
    if (b%2==0)
    // if (a%2==0)
    {
      printf("0");
      
    }
    else
    // else
    {
      printf("1");
      
    }
    b=b/2;
    
  }
  printf("\n");
/*  for (int i = 7; i >=0; i--)
  {
    // print one bit
    printf("%d", (a >> i) & 1);
    }*/
  /* int d[20];
  int i=0;
  while(a>0)
  {
    d[i]=a%2;
    i++;
    a=a%2;
  }

  for(int j=i-1; j>=0; j--)
  {
    printf("%d",d[j]);
    }*/
}

// Count the number of 1-bits (bits in a that are 1).
int byte_count_ones( const byte a ){
  int count=0;
  int x=a;
  while (x)
  {
    if ((x&1)==1)
    {
      count++
    }
    x=( x>>1);
  }
  return count;
  return 0;
}

// Performs "bit-wise and" operation
void byte_and( byte *a, const byte x, const byte y ){
 *a=x&y;
}

// Rotates a bit-wise to the right one position
// Note that this is not simply a shift
void byte_rotate_right( byte *a ){
  *a=*a<<7;
  
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
