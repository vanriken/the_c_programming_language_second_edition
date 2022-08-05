/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


// disables MinGW globbing that is added to this program (fixes problem with *)
// Source: https://willus.org/mingw/_globbing.shtml
extern int _CRT_glob = 0;

#define STACK_SIZE 15

unsigned char stack_pointer = 0;
float stack[STACK_SIZE];

void handle_error(const char *msg);
float pop(void);
void push(float element);

int main(int argc, char *argv[])
{
    int i;
	double value;

	for (i = 1; i < argc; ++i)
    {
		switch (argv[i][0])
        {
    		case '\0':
    			handle_error("Empty command line argument");
    			break;
    		case '0':
    		case '1':
    		case '2':
    		case '3':
    		case '4':
    		case '5':
    		case '6':
    		case '7':
    		case '8':
    		case '9':
    			push(atof(argv[i]));
    			break;
    		case '+':
    			push(pop() + pop());
    			break;
    		case '-':
    			value = pop();
    			push(pop() - value);
    			break;
    		case '*':
    			push(pop() * pop());
    			break;
    		case '/':
    			value = pop();
                if (value == 0)
                    handle_error("Division by zero.");
                else
                    push(pop() / value);
    			break;
    		default:
    			handle_error("Unknown operator. Supported: '+', '-', '*', '/'.");
    			break;
		}
	}

	printf("Result: %g\n", pop());
	return 0;
}

void handle_error(const char *msg)
{
	printf("Error: %s\n", msg);
	exit(EXIT_FAILURE);
}

float pop(void)
{
  if (stack_pointer > 0)
  {
    return stack[stack_pointer--];
  }
  else
  {
      printf("Error: the stack is empty.\n");
      return 0;
  }
}

void push(float element)
{
  if (stack_pointer < STACK_SIZE)
  {
    stack[++stack_pointer] = element;
  }
  else
  {
    printf("Error: the stack is full.\n");
  }
}
