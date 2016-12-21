class B
{
  virtual void foo() {printf("B");}
};

class X: public B
{
  virtual void foo() {printf("x");}
};

class Y : public B
{
  virtual void foo() {printf("Y");}
};

X *px=new X; px->foo();
Y *py= new Y; py->foo();
B *pb=px;
pb->foo();
pb =py;
pb->foo();

int N=1000;
B *objects[N];
objects[0]=new X;
objects[1]= new Y;

for (int i=0; i<N;i++)
{
  ovjects[i]->draw();
}
