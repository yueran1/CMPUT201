#pragma once

class decimal
{
public:
  decimal (int n);
  ~decimal ();
  void set(unsigned long long b);
  void add(int c);
  void print();
private:
  char *digits;
  int n;
  
};voi
