#include <stdio.h>

#define ALLOC_BUF_SIZE 10

/*
alloc takes in n which represents a single byte aka character position
it uses an intenrally accessible larger array called allocbuf and pulls pointer
to n bytes in allocbuf then that pointer is returned

afree takes in the originally returned pointer and frees up the corresponding
space up
*/

char allocbuf[ALLOC_BUF_SIZE];
char *allocp = allocbuf;

char *alloc(int n) {}

void afree(char *p) {}

int main() { char *a = alloc(3); }