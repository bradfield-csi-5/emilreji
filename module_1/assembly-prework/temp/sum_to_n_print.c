#include <stdio.h>

int sum_to_n(int n) {
    int total = 0;
    
    for (int i = 0; i <= n; i++)
        total += i;
    
    return total;
}

int main() {
    int sum = sum_to_n(5);
    printf("%d", sum);
}
