#include <stdio.h>

int main() {
    int bCounts = 0;
    int tCounts = 0;
    int nCounts = 0;
    int c;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            bCounts++;
        }

        if (c == '\t') {
            tCounts++;
        }

        if (c == '\n') {
            nCounts++;
        }
    }

    printf("\nBlank Counts: %d  Tab Counts: %d  Newline Counts: %d\n", bCounts, tCounts, nCounts);
}