#include <stdio.h>

int rand(void);
void srand(unsigned int seed);

unsigned long int next = 1;

int main(void)
{
    srand(2);  // set the seed for the rng

    for (int i = 0; i < 10; ++i)
    {
        printf("%d, ", rand());
    }
    return 0;
}

/* rand: return a pseudo-random integer on 0...32767 */
int rand(void)
{
    extern unsigned long int next;
    next = next * 1103515245 + 12345;
    return (unsigned int) (next/65536) % 32768;
}

/* srand: set seed for rand() */
void srand(unsigned int seed)
{
    extern unsigned long int next;
    next = seed;
}
