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

void printLine(char line[]) {
    if (line[0] == '\n') {
        return;
    }
    int i = 0;
    char c;
    putchar('"');
    while((c = line[i]) != '\0') {
        if (c == '\n') {
            putchar('"');
        }
        putchar(line[i]);
        i++;
    }
}

void reverseLine(char line[], int currLen) {
    int i, j;
    char temp;
    j = currLen - 1; // considering \0
    for(i = 0; i < j; i++) {
        temp =line[i];
        line[i] = line[j];
        line[j] = temp;
        j--;
    }
}


int main() {
    int currLen;
    char currLine[LINE_LENGTH];

    while(1) {
        currLen = (getLine(currLine, LINE_LENGTH));
        printf("currLen: %d\n", currLen);
        reverseLine(currLine, currLen);
        // printf("reversed: %s\n", currLine);
        printLine(currLine);
    }
}
