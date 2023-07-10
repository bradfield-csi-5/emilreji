#include <stdio.h>

int main(){
    int a[10] = { 4, 3 };
    int *pa = &a[0];
    int x = *pa;
    printf("a[0]: %d  pa: %p  x: %d  &x: %p\n", a[0], pa, x, &x); 
    // a[0]: 4  pa: 0x7ffcb43f7110  x: 4  &x: 0x7ffcb43f70f8
    // copies the data in first element of a into x

    int *pb = &a[1];
    int y = *(pa+1);
    printf("a[1]: %d  pa+1: %p  y: %d  &y: %p\n", a[1], (pa+1), y, &y); 
    // a[1]: 3  pa+1: 0x7ffcb43f7114  y: 3  &y: 0x7ffcb43f70fc
    // both a[0] and a[1] are addresses next to each other
    // x and y are seperate addresses from a[0] and a[1]
    // however x and y are addresses next to each other as well
}