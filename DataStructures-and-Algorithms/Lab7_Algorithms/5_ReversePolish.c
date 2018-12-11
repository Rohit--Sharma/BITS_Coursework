#include <stdio.h>
#include <stdlib.h> //for atof()
#include <math.h>

#define MAXOP 100 //max size of operand or operator
#define NUMBER '0' //signal that a number was found

int getop(char[]);
void ungetch(char[]);
void push(double);
double pop(void);

int main(int argc, char *argv[])
{
    double op2;
    char s[MAXOP];

    while(--argc > 0)
    {
        ungetch(" ");
        ungetch(*++argv);
        switch(getop(s))
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero devisior\n");
                break;
            default:
                printf("error: unknown command %s\n", s);
                argc = 1;
                break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}

#define MAXVAL 100 //maximum depth of val stack

double val[MAXVAL]; //value stack
int sp = 0; //next free stack position

/* push: push f into value stack */
void push(double f)
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can`t push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(char []);


/* getop: get next character ot numeric operand */
int getop(char s[])
{
    int i, c;
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.') // not a nember
        return c;
    i = 0;
    if(isdigit(c)) //collect integer part
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.') //collect fraction part
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];  //buffer for ungetch;
int bufp = 0; //next free position in bud

int getch(void) // get a (possibly pushed-back) character
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char argv[]) // push character back on input
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characnters\n");
    else
        buf[bufp++] = *argv;
}