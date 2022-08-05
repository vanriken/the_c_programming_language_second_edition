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

#define XMAX 1024
#define YMAX 768

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int x, int y);
struct point addpoints(struct point p1, struct point p2);
int ptinrect(struct point p, struct rect r);
struct rect canonrect(struct rect r);

int main(void)
{
    struct rect screen;
    struct point origin, *pp;  // struct and pointer to struct

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);

    printf("screen.pt1: %d, %d\n", screen.pt1.x, screen.pt1.y);
    printf("screen.pt2: %d, %d\n", screen.pt2.x, screen.pt2.y);

    origin = makepoint(0, 0);
    pp = &origin;
    printf("origin is (%d, %d)\n", (*pp).x, (*pp).y);
    printf("origin is (%d, %d)\n", pp->x, pp->y);  // alternative short-hand notation

    return 0;
}

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

/* addpoints: add two points
structure parameters are passed by value (copy) */
struct point addpoints(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: return 1 if point is in rectangle, 0 if not
assumes that rectangle is represented in a stardard form where
pt1 coordinates are less than the pt2 coordinates */
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;

}

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}
