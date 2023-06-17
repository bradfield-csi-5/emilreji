#include <stdio.h>

#define LINE_LENGTH 100

int getLine(char s[], int lim) {
    int c, currLen, i;
    currLen = 0;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF; i++) {
        s[i] = c;
        currLen++;

        if (c == '\n'){
            break;
        }
    }
    s[i + 1] = '\0';

    return i;
}

void copy(char to[], char from[]) {
    for(int i = 0; i < LINE_LENGTH; i++) {
        to[i] = from[i];
    }
}

void printLine(char line[]) {
    printf("\nLongest Line: \"");
    int i = 0;
    char c;

    while((c = line[i]) != '\0') {
        putchar(line[i]);
        i++;
    }
    putchar('"');
}

int main() {
    int c, currLen, maxLen;
    char currLine[LINE_LENGTH];
    char maxLine[LINE_LENGTH];
    maxLen = 0;

    while((currLen = getLine(currLine, LINE_LENGTH))) {
        if (currLen > maxLen){
            maxLen = currLen;
            copy(maxLine, currLine);
        }
    }

    printf("\nLength of longest line: %d\n", maxLen);
    printLine(maxLine);
}