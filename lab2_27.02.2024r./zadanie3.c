#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Point;

void zmienWspolrzedne(int *x, int *y)
{
    (*x) *=5;
    (*y) *=3;
}

typedef struct
{
    Point a;
    Point b;
    Point c;
    Point d;
} Rectangle;

void poleIObwod(Point *a, Point *b, Point *c, Point *d)
{
    
}

int main()
{
  Point p;
  p.x = 2;
  p.y = 6;
  zmienWspolrzedne(&p.x, &p.y);
  printf("%d, %d", p.x, p.y);
}
