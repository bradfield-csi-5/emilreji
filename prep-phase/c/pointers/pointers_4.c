#include <stdio.h>

int main() {
    int x = 5;
    int *px = &x;
    printf("x: %d  px: %p\n", x, px); 
    // x: 5  px: 0x7ffe44fbbe9c

    *px = *px + 1;
    printf("x: %d  px: %p\n", x, px); 
    // x: 6  px: 0x7ffe44fbbe9c
    // here the px pointer variable is dereferenced to get the value stored there
    // that value of 5 is incremented and then stored where px references
    // hence why x is updated

    *px = *(px + 1);
    printf("x: %d  px: %p\n", x, px); 
    // x: 1157349020  px: 0x7ffe44fbbe9c
    // here, the px pointer variable is incremented first before dereferencing
    // that value (memory address) is stored in decimal format into where px references
    // hence why x is updated
    // https://www.rapidtables.com/convert/number/decimal-to-hex.html
    // 1157349020 converts to 44FBBE9C which is latter half of px memory address
    // note we want to look at Hex signed 2's complement (8 digits)
}