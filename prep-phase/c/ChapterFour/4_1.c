#include <stdio.h>

int strindex(char s[], char t[]){
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++){
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++){}
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}

// int findLength(char s[]) {
//     int i;
//     for(i = 0; s[i] != '\0'; i++) {}
//     return i;
// }

// finds length and iterate backwards

// int strindexright(char s[], char t[]){
//     int i, j, k;
//     int sLength = findLength(s);
//     int tLength = findLength(t);

//     for (i = sLength - 1; i >= 0; i--){
//         for (j = i, k = tLength - 1; k >= 0 && s[j] == t[k]; j--, k--){}
//         if (k < 0){
//             return i - tLength + 1;
//         }
//     }
//     return -1;
// }

/*
Same logic as strindex but once correct value found, stores and keeps looking
Once we hit end of s, then we return what we have stored or -1
*/
int strindexright(char s[], char t[]){
    int i, j, k;
    int currResult = -1;
    for (i = 0; s[i] != '\0'; i++){
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++){}
        if (k > 0 && t[k] == '\0') {
            currResult = i;
        }
    }
    return currResult;
}


int main() {
    char s[15] = "this is a test";
    char t[4] = "is";

    // printf("%d  %c\n", findLength(t), t[findLength(t) - 1]);

    int location = strindex(s, t);
    int locationRight = strindexright(s, t);

    printf("location: %d  char: %c   locationRight: %d  char: %c\n", location, s[location], locationRight, s[locationRight]);
}