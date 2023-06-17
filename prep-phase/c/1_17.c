#include <stdio.h>

#define LINE_LENGTH 100
#define MAX_LINES 20
#define TARGET_LINE_LENGTH 80

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
    int i = 0;
    char c;

    while((c = line[i]) != '\0') {
        putchar(line[i]);
        i++;
    }
}

int main() {
    int c, currLen, currLineIdx;
    char currLine[LINE_LENGTH];
    char lines[MAX_LINES][LINE_LENGTH];
    currLen = 0;
    currLineIdx = 0;

    while((currLen = getLine(currLine, LINE_LENGTH))) {
        if (currLen > TARGET_LINE_LENGTH){
            copy(lines[currLineIdx], currLine);
            currLen++;
        }
    }

    for(int i = 0; i < MAX_LINES; i++) {
        printLine(lines[i]);
    }
}