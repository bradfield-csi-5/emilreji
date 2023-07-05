#include <stdio.h>

void squeeze(char s[], int c) {
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

int main() {
    int c = 't';
    char s[15] = "this is a test";
    printf("%s\n", s);
    squeeze(s, c);
    printf("%s\n", s);
}