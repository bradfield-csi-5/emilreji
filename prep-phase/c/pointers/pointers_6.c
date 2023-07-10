#include <stdio.h>

int setNumToTen(int *numPtr) {
    printf("*numPtr: %d  numPtr: %p\n", *numPtr, numPtr); 
    *numPtr = 10;
    printf("*numPtr: %d  numPtr: %p\n", *numPtr, numPtr);  
}

int main() {
    int x = 5;
    int *px = &x;
    printf("x: %d  px: %p\n", x, px); 
    // x: 5  px: 0x7ffdc249833c

    setNumToTen(px);
    // *numPtr: 5  numPtr: 0x7ffdc249833c 
    // *numPtr: 10  numPtr: 0x7ffdc249833c

    printf("x: %d  px: %p\n", x, px); 
    // x: 10  px: 0x7ffdc249833c

    // in comparison to pointers_5.c, we pass in a pointer of x into setNumToten
    // the memory address outputted inside setNumToTen is the same as the memory address in main
    // hence the value of x is changed to 10 as a result of running setNumToTen
    // So in order to change a value inside a function without global variables, we need to pass in pointers
    
}