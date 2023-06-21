#include <stdio.h>

#define SPACES_PER_TAB 8

int main() {
    int c, nonTabPrevLen;
    while((c = getchar()) != EOF){
        if (c == '\t') {
            int spaces = SPACES_PER_TAB - (nonTabPrevLen % SPACES_PER_TAB);
            for(; spaces > 0; spaces--) {
                putchar(' ');
            }
            // printf("\nspaces: %d\n", (SPACES_PER_TAB - (nonTabPrevLen % SPACES_PER_TAB)));
            nonTabPrevLen += spaces;
        } else {
            putchar(c);
            nonTabPrevLen++;
            if (c == '\n')
                nonTabPrevLen = 0;
        }
    }
}

// int main() {
//     printf("\t,\n");
//     printf(".\t,\n");
//     printf("..\t,\n");
//     printf("...\t,\n");
//     printf("....\t,\n");
//     printf(".....\t,\n");
//     printf("......\t,\n");
//     printf(".......\t,\n");
//     printf("........\t,\n"); // 8 characters per tab
//     printf(".........\t,\n");
//     printf("..........\t,\n");
// }