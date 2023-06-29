#include <stdio.h>

int main() {
    int result = getchar() != EOF;
    if (result == 1) {
        printf("Result is 1\n");
    }
    if (result == 0) {
        printf("Result is 0\n");
    }
    printf("%d\n", result);
}
// https://stackoverflow.com/questions/4358728/end-of-file-eof-in-c