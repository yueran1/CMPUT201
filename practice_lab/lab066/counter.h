#pragma once

class counter
{
public:
  counter(unsigned int i);

  ~counter();
  void tick();
  bool done();
private:
  unsigned int i;
}
