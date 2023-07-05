#include <stdio.h>

#define IN_STRING 1
#define NOT_IN_STRING 0

void squeeze(char s[], char c[]) {
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++) {
        int status = NOT_IN_STRING;
        for(int k = 0; c[k] != '\0'; k++){
            if (s[i] == c[k]) {
                status = IN_STRING;
            }
        }
        printf("s: '%s' status: %d   i: %d   j: %d\n", s, status, i, j);
        if (status == NOT_IN_STRING) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

// book solution (j and k are mixed in my edited version of book solution)
// void squeeze(char s[], char c[]) {
//     int i, j, k;
//     for(i = j = 0; s[i] != '\0'; i++) {
//         int status = NOT_IN_STRING;
//         for(k = 0; c[k] != '\0' && s[i] != c[k]; k++){}
//         printf("s: '%s' status: %d   i: %d   j: %d\n", s, status, i, j);
//         if (c[k] == '\0') { 
//             s[j++] = s[i];
//         }
//     }
//     s[j] = '\0';
// }
// when c[k] != '\0' is used, it removes all characters in s that don't match c
// when c[k] == '\0' is used, it removes all characters in s that match c


int main() {
    char c[4] = "tha";
    char s[15] = "this is a test";
    printf("'%s'\n", s);
    squeeze(s, c);
    printf("'%s'\n", s);
}