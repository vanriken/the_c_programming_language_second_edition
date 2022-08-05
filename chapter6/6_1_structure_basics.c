/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {  // point is the structure tag
    int x;  // x is a member of the structure
    int y;
};

/*
Structures can be nested
To represent a rectangle we can use a pair of points that denote diagonally opposite corners

struct rect {
    struct point p1;
    struct point p2;
};

example:

struct rect screen;

then screen.p1.x refers to the x-coordinate of the pt1 member of screen

*/

int main(void)
{
    struct point pt = {4, 4};
    printf("Coordinates: %d, %d\n", pt.x, pt.y);

    double dist;
    dist = (double) sqrt(pt.x * pt.x + pt.y * pt.y);
    printf("Distance from origin: %g\n", dist);
}
