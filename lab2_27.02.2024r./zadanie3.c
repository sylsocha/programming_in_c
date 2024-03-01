#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

float dlugoscOdcinka(Point *a, Point *b)
{
    float pierwSkladnik = pow(((*a).x - (*b).x), 2);
    float drugiSkladnik = pow(((*a).y - (*b).y), 2);
    return sqrt(pierwSkladnik + drugiSkladnik);
    
}

void poleIObwod(Point *a, Point *b, Point *c, Point *d)
{
    
}

int main()
{
  Point p;
  p.x = 2;
  p.y = 6;
  
  Point r;
  r.x = 1;
  r.y = 4;
  //zmienWspolrzedne(&p.x, &p.y);
  //printf("%d, %d\n", p.x, p.y);
  
  printf("%f", dlugoscOdcinka(&p, &r));
}
