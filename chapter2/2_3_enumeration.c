#include <stdio.h>

int main(void)
{
    enum days {MON = 1, TUE, WED, THU, FRI, SAT, SUN};  // TUE is 2, WED is 3 etc.
    printf("SUN = %d\n", SUN);
    return 0;
}
