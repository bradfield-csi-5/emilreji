#include <stdio.h>

int any(char s1[], char s2[]) {
    for(int i = 0; s1[i] != '\0'; i++) {
        for(int j = 0; s2[j] != '\0'; j++) {
            // printf("i: %d   j: %d    s1[i]: %c   s2[j]: %c\n", i, j, s1[i], s2[j]);
            if(s1[i] == s2[j]) {
                return i;
            }
        } 
    }
    return -1;
}

int main() {
    char s1[15] = "This is a test";
    char s2[4] = "ta";

    int location = any(s1, s2);

    printf("location: %d  char: %c\n", location, s1[location]);
}