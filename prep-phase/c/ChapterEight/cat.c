#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// #define BUFSIZ 1000 
// default from /usr/include/stdio.h:99 is 8192

/*
Rewrite the program cat from Chapter 7 using read, write, open, and close
instead of their standard library equivalents. Perform experiments to determine the relative
speeds of the two versions.
*/

int main(int argc, char *argv[])
{
    FILE *fp;
    int fd;
    // int open(char *, int, int); // figure out why this conflicts
    void filecopy(int, int);
    char *prog = argv[0]; /* program name for errors */

    printf("Print %d arguments\n", argc); // total args after ./a.out call

    for(int i = 0; i < argc; i++) { // printing each arg after ./a.out call
        printf("argument %d: %s\n", i, argv[i]);
    }

    if (argc == 1)
    { /* no args after ./a.out other than file name; copy standard input */
        // filecopy(stdin, stdout);
        printf("No valid file names passed in so copying stdin to stdout\n");
        filecopy(0, 1);
    }
    else
    { 
        // argv starts by pointing to current file name (./a.out) so must increment to after it
        // that argument is assumed to be a file name and opened, copied, and printed out
        while (--argc > 0) // 
        { 
            // if ((fp = fopen(*++argv, "r")) == NULL)
            if ((fd = open(*++argv, O_RDONLY, 0)) < 0) // try O_RDONLY for 2nd arg
            {
                fprintf(stderr, "%s: can't open %s \n", prog, *argv);
                exit(1);
            }
            else
            {
                filecopy(fd, 1);
                close(fd);
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

void filecopy(int ifd, int ofd)
{
    int readBytesNum, writeBytesNum;
    char buf[BUFSIZ];

    while ((readBytesNum = read(ifd, buf, BUFSIZ)) > 0)
    {
        printf("\nreadBytesNum: %d\n\n\n", readBytesNum);

        writeBytesNum = write(ofd, buf, readBytesNum);
        // printf("writeBytesNum: %d", writeBytesNum);
        if (writeBytesNum < 0) {
            printf("error writing\n");
            exit(0);
        }
    }

    if (readBytesNum < 0) {
            printf("error reading\n");
            exit(0);
    }

    printf("\n\n\nreadBytesNum: %d writeBytesNum: %d\n", readBytesNum, writeBytesNum);
}