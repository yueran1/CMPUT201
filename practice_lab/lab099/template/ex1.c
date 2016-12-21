

struct Point {
  int x, y;
  bool is_greater_than(const Point &a,const Point &b)
    {
        if (a.x>b.x) return true;
        return a.x==b.x && a.y>b.y;
    }

};



template <typename T> T max(T x, T y) {
    return x > y ? x : y;
  }
// assuming type Foo doesn't support >

int max(int x, int y)
{
  return is_greater_than(x, y) ? x : y;
}








 



 
  int x, y;
  x = max(x, y);
// calls Foo max function, rather
// txhan template function max
}
