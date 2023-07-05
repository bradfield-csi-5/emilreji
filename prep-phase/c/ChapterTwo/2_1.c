#include <stdio.h>
#include <limits.h>

void leftShiftToMaxChar() {
    char i = 2;

    while(i > 0){
        i = i << 1;
        // printf("%d\n", i);
    } 

    printf("CHAR range: %d to %d\n", i, ((i + 1) * -1));
}

void leftShiftToMaxLong() {
    long i = 2;

    while(i > 0){
        i = i << 1;
    }

    printf("LONG range: %lu to %lu\n", i, ((i + 1) * -1));
}

int main(){
    printf("CHAR range: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("CHAR UNSIGNED range: %d to %u\n", 0, UCHAR_MAX);

    printf("SHORT range: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("SHORT UNSIGNED range: %d to %hu\n", 0, USHRT_MAX);

    printf("INT range: %d to %d\n", INT_MIN, INT_MAX);
    printf("INT UNSIGNED range: %d to %u\n", 0, UINT_MAX);

    printf("LONG range: %lu to %lu\n", LONG_MIN, LONG_MAX);
    printf("LONG UNSIGNED range: %d to %lu\n", 0, ULONG_MAX);
    // https://stackoverflow.com/questions/2844/how-do-you-format-an-unsigned-long-long-int-using-printf
    printf("\n");

    leftShiftToMaxChar();
    leftShiftToMaxLong();
}