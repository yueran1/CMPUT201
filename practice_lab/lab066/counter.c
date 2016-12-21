#include"counter.h"
#include<cassert>

counter::counter(unsigned int i)
{
  int value=i;
}

~counter:: counter()
{
  //destructor does no do anything
}

void counter:: trick()
{
  if (value>0)
  {
    value--;
  }
}

bool counter:: done() const
{
  if (value==o)
  {
    return true;
  }

  else
  {
    return false;
  }
}
