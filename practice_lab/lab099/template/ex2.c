struct Point {
  int x, y;
  void operator=(const Point &u)// assignment
    {
      x = u.x; y = u.y;
// copy all components
    }
};
// returns true iff point a is lexicographically
// smaller than point b
bool operator<(const Point &a, const Point &b)
{
  if (a.x < b.x) return true;
  return a.x == b.x && a.y < b.y;
}
Point a, b;
a=b;
