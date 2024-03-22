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

void poleIObwod(Rectangle *rect)
{
    float ab = dlugoscOdcinka(&rect->a, &rect->b);
    float bc = dlugoscOdcinka(&rect->b, &rect->c);
    float cd = dlugoscOdcinka(&rect->c, &rect->d);
    float ad = dlugoscOdcinka(&rect->a, &rect->d);

    float obwod = ab+bc+cd+ad;
    printf("%f\n", obwod);

    float pole = ab*bc;
    printf("%f\n", pole);
}

int main()
{
    Point t;
    t.x = 3;
    t.y = 8;


    Rectangle rect;
    rect.a.x = 2;
    rect.a.y = 6;
    rect.b.x = 5;
    rect.b.y = 6;
    rect.c.x = 5;
    rect.c.y = 1;
    rect.d.x = 2;
    rect.d.y = 1;

    zmienWspolrzedne(&t.x, &t.y);
    printf("%d, %d\n", t.x, t.y);

    poleIObwod(&rect);
}
