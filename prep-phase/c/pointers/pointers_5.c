#include <stdio.h>

int setNumToTen(int num) {
    printf("num: %d  &num: %p\n", num, &num); 
    num = 10;
    printf("num: %d  &num: %p\n", num, &num); 
}

int main() {
    int x = 5;
    int *px = &x;
    printf("x: %d  px: %p\n", x, px); 
    // x: 5  px: 0x7ffe0ad44f8c

    setNumToTen(x);
    // num: 5  &num: 0x7ffe0ad44f6c 
    // num: 10  &num: 0x7ffe0ad44f6c

    printf("x: %d  px: %p\n", x, px); 
    // x: 5  px: 0x7ffe0ad44f8c

    // a totally different memory address is allocted as part of setNumToTen for num in comparison to x
    // the number inside it is changed but once we return to main x hasn't changed
}