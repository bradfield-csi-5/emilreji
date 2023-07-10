#include <stdio.h>

int main() {
    int x = 5;
    int *px = &x;
    printf("x: %d  px: %p\n", x, px);
    // x: 5  px: 0x7ffc667482f8

    int *py = px;
    int y = *py;
    int *py2 = &y;
    printf("x: %d  px: %p  y: %d  py: %p  py2: %p\n", x, px, y, py, py2);
    // x: 5  px: 0x7ffc667482f8  y: 5  py: 0x7ffc667482f8  py2: 0x7ffc667482fc
    y = 3;
    printf("x: %d  px: %p  y: %d  py: %p  py2: %p\n", x, px, y, py, py2);
    // x: 5  px: 0x7ffc667482f8  y: 3  py: 0x7ffc667482f8  py2: 0x7ffc667482fc
    *px = 1;
    printf("x: %d  px: %p  y: %d  py: %p  py2: %p\n", x, px, y, py, py2);
    // x: 1  px: 0x7ffc667482f8  y: 3  py: 0x7ffc667482f8  py2: 0x7ffc667482fc

    // results are slightly different from pointers_1.c and pointers_2.c
    // in previous 2 files, px and py had different but consistent memory addresses
    // here both px and py have the same memory address that never changes
    // this is because py is created from px and then y is created after
    // so px and py point to where x's value is stored
    // meanwhile py2 points to where y's value is stored
    // this explains why the values of x and y change with reassignments but px and py don't change
}