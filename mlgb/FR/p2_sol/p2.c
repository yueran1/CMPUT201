#include <stdio.h>
#include <assert.h>

struct Point { int x; int y; };

int main()
{

  struct Point p[20];

  char input_file[] = "landscape.txt";
  
  FILE *fp = fopen(input_file, "r");  // open file for read
  if (fp == NULL) {
    return 1;
  }

  int index = 0;

  int valueX, valueY;

  // read two ints at a time
  while (fscanf(fp, "%d %d", &valueX, &valueY) == 2)
  {

    assert(index < 20);
    
    p[index].x = valueX;
    p[index].y = valueY;

    index++;
  }
  
  if (fclose(fp) == EOF) {  // close the file
    return 1;
  }

  // print the values from the array
  for (int i = 0; i < index; i++)
  {
    printf("%d %d\n", p[i].x, p[i].y);
  }
  
  return 0;

}
