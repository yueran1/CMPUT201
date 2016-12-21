# include<stdio.h>
# include"decimal.h"
# include<assert.h>

decimal:: decimal(int a)
{
  assert(a>0);
  n=a;
  digits=new char[a];
  
}

~decimal :: decimal()
{
  delete [] digits;
}

void decimal:: set(unsigned long long b)
{
  unsigned long long b_=b;
  for (int i=0, i<n, i++)
  {
    digits[i]=(char) (d_%10);
    d_ =/10;
  }

  if (b_)
  {
    printf( "Decimal::set overflow %llu\n", b_ );
    exit(1);
  }
}


/*void decimal:: add(const decimal &c)
{
  
  digits[n+1]=c_;
  if (c_)
  {
     printf( "Decimal::set overflow %llu\n", c_ );
    exit(1);
  }
  }*/

void decimal:: add(const decimal &c)
{
  int carry=0;
  assert(c.n==n)
    for (int i =0;i<n; ++i)
    {
      int sum=digits[i]+d.digits[i]+carry;
      carry=sum/10;
      disits[i]=(char) (sum%10);
      
      
    }
  if (carry)
  {
    printf( "Decimal::add overflow\n" );
    exit(1);
  }
}

// print digits (high-order first) to stdout; skip leading 0s
void Decimal::print() const
{
  int i;

  // skip leading 0s
  for (i=n-1; i > 0; --i) {
    if (digits[i])
      break;
  }

  for (; i >= 0; --i) {
    printf( "%d ", (int)digits[i]); 
  }
}
