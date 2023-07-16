#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0]; /* program name for errors */

    printf("Print %d arguments\n", argc);

    int i;
    for(int i = 0; i < argc; i++) { // printing each arg after ./a.out call
        printf("argument %d: %s\n", i, argv[i]);
    }
    printf("terminating char: %s\n", argv[i]); // terminating char: (null)

    if (argc == 1)
    { /* no args; copy standard input */
        filecopy(stdin, stdout);
    }
    else
    {
        while (--argc > 0)
        {
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                fprintf(stderr, "%s: can't open %s \n", prog, *argv);
                exit(1);
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }

        if (ferror(stdout))
        {
            fprintf(stderr, "%s: error writing stdout\n", prog);
            exit(2);
        }

        exit(0);
    }
}

void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while ((c = getc(ifp)) != EOF)
    {
        putc(c, ofp);
    }
}