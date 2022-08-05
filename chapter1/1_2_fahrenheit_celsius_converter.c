#include <stdio.h>

#define LOWER 0  // lower limit of temperature table
#define UPPER 300  // upper limit
#define STEP 20  // step size

/* Print Fahrenheit to Celsius table
for fahr = 0, 20, ..., 300 */

int main()
{
    float fahr, celsius;
    printf("Fahrenheit\tCelsius\n");
    fahr = LOWER;
    while (fahr <= UPPER)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%10.0f\t%7.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }
}

/* Same output using a for loop */

// int main()
// {
//     int fahr;
//
//     printf("Fahrenheit\tCelsius\n");
//     for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
//     {
//         printf("%10d\t%7.1f\n", fahr, (5.0/9.0)*(fahr-32));
//     }
// }
