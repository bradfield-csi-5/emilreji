#include <stdio.h>

#define ALLOCSIZE 10

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
    int charLeft = allocbuf + ALLOCSIZE - allocp;
    if (charLeft >= n) {
        printf("Allocating %d characters from %d characters left\n", n, charLeft);
        allocp += n;
        return allocp - n;
    } else {
        printf("Error allocating %d characters from %d characters left\n", n, charLeft);
        return 0;
    }
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        printf("Deallocating %ld characters\n", allocp - p);
        allocp = p;
    }
}

void print() {
    printf("'%s'\n", allocbuf);
}

int main() {
    print();
    char* p = alloc(3);
    print();
    *p = 'e';
    print();
    p[0] = 'f';
    print();
    *(p + 1) = 'g';
    print();
    p[1] = 'h';
    print();
    afree(p);
    print();
    afree(p);
    print();
}
