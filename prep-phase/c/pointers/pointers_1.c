#include <stdio.h>

int main(){
    int x = 5;
    int *px = &x;
    printf("x: %d  px: %p\n", x, px); 
    // x: 5  px: 0x7ffc303c2080

    int y = *px;
    int *py = &y;
    printf("x: %d  px: %p  y: %d  py: %p \n", x, px, y, py);
    // x: 5  px: 0x7ffc303c2080  y: 5  py: 0x7ffc303c2084
    // py seems to be right after px but not identical memory address
    // in other words, x and y aren't the same integer in memory
    y = 3;
    printf("x: %d  px: %p  y: %d  py: %p \n", x, px, y, py);
    // x: 5  px: 0x7ffc303c2080  y: 3  py: 0x7ffc303c2084 
    // when y is assigned a new value, the memory addresses remain the same and x isn't touched
    // this confirms that x and y are stored at different memory addresses
    // if they were the same, reassigned y should also change x
    *px = 1;
    printf("x: %d  px: %p  y: %d  py: %p \n", x, px, y, py);
    // x: 1  px: 0x7ffc303c2080  y: 3  py: 0x7ffc303c2084 
    // similar to y = 3, we are updating x to a new value
    // however this time we are doing it through the memory address directly
    // we dereference px and direclty put 1 inside the memory address of x
    
}