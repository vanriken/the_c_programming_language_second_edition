#include <stdio.h>

#define LOWER 0  // lower limit of temperature table
#define UPPER 300  // upper limit
#define STEP 20  // step size

/* Print Fahrenheit to Celsius table
for fahr = 0, 20, ..., 300 */

// function declaration
void fahrenheit_to_celsius(void);

int main()
{
    fahrenheit_to_celsius();
    return 0;
}

void fahrenheit_to_celsius(void)
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
