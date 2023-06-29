#include <stdio.h>

void printDashes(int num) {
    int i = 0;
    while (i < num) {
        putchar('-');
        i++;
    }
    putchar('\n');
}

int main()
{
    int c, i, nwhite, nother;
    int ndigit[10];
    nwhite = nother = 0;

    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("\ndigits | amount\n");

    for (i = 0; i < 10; ++i) {
        printf("%d count |", i);
        printDashes(ndigit[i]);
    }
    printf("white space | ");
    printDashes(nwhite);

    printf("other | ");
    printDashes(nother);
}