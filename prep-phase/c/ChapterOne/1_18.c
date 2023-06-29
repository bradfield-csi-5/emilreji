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
    } // \t\t\n and i = 2
    i++;  // \t\t\n and i = 3
    s[i] = '\0';  // \t\t\n\0 and i = 3
    i--;  // \t\t\n\0 and i = 2

    // loop 1: \t\t\n\0 and i = 1
    // since its a tab, new is \t\n\0\0
    // loop 2: \t\n\0\0 and i = 0
    // since its a tab, new is \n\0\0\0
    while(i >= 0){
        i--;   
        char *c = &s[i];
        // printf("current index: %d and val %c\n", i, c);
        if (s[i] == ' ' || s[i] == '\t') {
            // printf("updating curr index with null character\n");
            s[i + 1] = '\0';
            s[i] = '\n';
        } else {
            break;
        }
    }

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
        // printf("%c", line[i]);
        i++;
    }
}

int main() {
    char currLine[LINE_LENGTH];

    while((getLine(currLine, LINE_LENGTH))) {
        printLine(currLine);
    }
}

/*
Use getline to get the current line in main
Then pass it to seperate function to remove trailing tabs and blanks
Iterate backwards on the string with loop end clause being current string isn't a tab or blank
If current character is tab or blank, set to /0; keep doing this until we break
Once done, ouptut line like normal

*/