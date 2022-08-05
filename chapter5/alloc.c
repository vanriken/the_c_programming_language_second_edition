#define ALLOCSIZE 10000  // available space

static char allocbuf[ALLOCSIZE];  // storage for alloc
static char *allocp = allocbuf;  // next free position

char *alloc(int n)  // return pointer to n characters
{
    if (allocbuf + ALLOCSIZE - allocp >= n)  // it fits
    {
        allocp += n;
        return allocp - n;  // old pointer
    }
    else  // not enough room in allocbuf
    {
        return 0;
    }
}

void afree(char *p)  // free storage pointed to by p
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)  // check that p is inside the buffer
        allocp = p;
}
