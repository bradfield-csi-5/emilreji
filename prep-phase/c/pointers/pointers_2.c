#include <stdio.h>

int main() {
    int x = 5;
    int *px = &x;
    printf("x: %d  px: %p\n", x, px); 
    // x: 5  px: 0x7ffd666956a0

    int y = x;
    int *py = &y;
    printf("x: %d  px: %p  y: %d  py: %p \n", x, px, y, py);
    // x: 5  px: 0x7ffd666956a0  y: 5  py: 0x7ffd666956a4 
    y = 3;
    printf("x: %d  px: %p  y: %d  py: %p \n", x, px, y, py);
    // x: 5  px: 0x7ffd666956a0  y: 3  py: 0x7ffd666956a4 
    *px = 1;
    printf("x: %d  px: %p  y: %d  py: %p \n", x, px, y, py);
    // x: 1  px: 0x7ffd666956a0  y: 3  py: 0x7ffd666956a4 

    // results are exactly the same as pointers_1.c
    // seems whether we set y = x or we set y = *px, the end result is the same
    // x and y use seperate memory addresses to hold their values and no cross over ever occurs
}