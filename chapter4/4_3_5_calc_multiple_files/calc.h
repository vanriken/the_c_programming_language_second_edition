/* We want to centralize as much as possible the definitions and
   declarations shared among the files. In this way, there is only
   one copy to get right and keep right as the program evolves.
   We place this material in a so called header file (calc.h) */
#define NUMBER '0'
#define MAXLINE 1000

void push(double);
double pop(void);
int getop(char []);
int getline(char [], int);

extern char line[];
extern int line_i;
