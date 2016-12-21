template <typename T> T max(T x, T y)
{
  return x>y? x:y;
}

float x ,y;
float m=max(x,y);

Point p,q;
Point r=max (p,q);

typedef const char *ccptr;
ccptr s="foo", t="bar";
ccptr u= max(s,t);
