#include <stdio.h>

int main() {
    int x = 9;
    printf("%d\n", sizeof(x)); // 4 bytes for integer
    float y = 9.0;
    printf("%d\n", sizeof(y)); // 4 bytes for float
    double z = 9.0;
    printf("%d\n", sizeof(z)); // 8 bytes for double
}