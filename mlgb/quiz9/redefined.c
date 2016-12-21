struct Point
{
  int x, y;
  void operator=(const Point &u)
    {
      x=u.x; y= u.y;
    }
};

bool operator< (const Point &a, const Point &b)
{
  if (a.x < b.x) return true;
  return a.x==b.x && a.y<b.y;
}

Point a,b;
a=b;
if (a<b);
