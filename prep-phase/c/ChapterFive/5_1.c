#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 10

char buf[BUFSIZE];
int bufp = 0;
/* buffer for ungetch */
/* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
/* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); // it is not a number
        // return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' && c == '-')
    {
        c = getch();
    }
    printf("start: *pn: %d  c: %d\n", *pn, c);
    // for (*pn = 0; c >= '0' && c <= '9'; c = getch())
    //     *pn = 10 * *pn + c - '0';
    for (*pn = 0; isdigit(c); c = getch())
    {
        // printf("*pn: %d  c: %d\n", *pn, c);
        *pn = 10 * *pn + (c - '0');
        // printf("*pn: %d  c: %d (c - '0'):%d \n", *pn, c, (c - '0'));
    }
    printf("end: *pn: %d  c: %d\n", *pn, c);
    *pn *= sign;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}

int main()
{
    int n, array[BUFSIZE];
    for (n = 0; n < BUFSIZE && getint(&array[n]) != EOF; n++)
        ;
    printf("\n\nPrinting array data:\n");
    for (n = 0; n < BUFSIZE; n++)
    {
        printf("%d: %d\n", n, array[n]);
    }
}
