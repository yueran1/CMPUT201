#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<assert.h>
struct point{int x; int y;};
int main()
{
  //struct point{int x; int y;};
  struct point p[20];
  char input_file[]="landscape.txt";
  FILE *fp=fopen(input_file,"r");
  if(!fp)
  {
    perror("encountered fopen error \n");exit(10);
  }
  int index=0;
  for (int i=0;i<20;++i)
  {
    int a,b;
    if(fscanf(fp, "%d %d", &a,&b)==2)
    {
      assert(i<20);
      p[i].x=a;
      p[i].y=b;
      index++;
// printf("encountered read error \n"); exit(10);
    }
    // p[i].x=a;
    //p[i].y=b;
  }
  /*int index=0;
  int a;
  int b;
  while (fscanf(fp, "%d %d", &a, &b) == 2)
  {

    assert(index < 20);

    p[index].x = a;
    p[index].y = b;

    index++;
  }
  printf("index is %d \n",index);*/
  
  
  if(fclose(fp)==EOF)
  {
    perror("encoutered fclose error \n"); exit(10);
  }

  for (int i=0; i<index;++i)
  {
    // assert(i<20);
    printf("%d %d \n", p[i].x, p[i].y);
  }
  return 0;
}
