/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:       Static vs Global variables:
                    https://stackoverflow.com/questions/2271902/static-vs-global

***********************************************************************/
#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
    int year = 2020;
    int nday = 160;

    // what is the 152nd day of 2022
    int month;
    int day;
    month_day(year, nday, &month, &day);
    printf("month: %d, day: %d\n", month, day);

    // does day of year give the correct result
    printf("Day of year: %d", day_of_year(year, month, day));
    return 0;
}

static char normal_year[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char leap_year[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char extra_row[] = {"Third row with different length!"};
static char *daytab[] = {normal_year, leap_year, extra_row};

/* day_of_year: set day of year from month and day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    for (i = 1; i < month; i++)
        day += *(daytab[leap] + i);
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= *(daytab[leap]+i);

    *pmonth = i;
    *pday = yearday;
}
