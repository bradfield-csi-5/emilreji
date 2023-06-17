#include <stdio.h>

int main(){
    int curr, whiteCount, otherCount;
    whiteCount = 0;
    otherCount = 0;

    int result[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    while((curr = getchar()) != EOF) {
        if (curr >= '0' && curr <= '9') {
            result[curr-'0']++;
        } else if (curr == ' ' || curr == '\t' || curr == '\n') {
            whiteCount++;
        } else {
            otherCount++;
        }
    }

    printf("\n");

    int i = 0;
    while (i < 10) {
        printf("%d count: %d\n", i, result[i]);
        i++;
    }

    printf("whiteCount: %d\notherCount: %d\n", whiteCount, otherCount);

}

/*
10 digits each, white space (blank, tab, newline all together), other
12 values to keep track of; use array

Missed:
When checking for 0 to 9, need to check as characters since receiving character data
Also to convert character to numeric index in result array, do this: num - '0'
This works since 0 to 9 character values have consecutive increasing values

*/