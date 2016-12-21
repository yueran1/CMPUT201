struct Shape
{
private:
  Color clocr;
  Point location;
public:
  void draw() {printf("undefined");exit(10);}
  void set_color(Color c){color=c;}
};

struct Circle: public Shape
{
private:
  int radius;
public:
  void draw()
    {
    }
};

Circle c;
c.set_cokor(0);
c.draw();
