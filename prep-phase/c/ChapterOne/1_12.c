#include <stdio.h>

#define IN  1 // inside a word
#define OUT 0 // outside a word

int isValid(c) {
    return c != ' ' && c != '\t' && c != '\n';
}

int main() {
    int wc, state, curr;
    wc = 0;
    state = OUT;

    while((curr = getchar()) != EOF) {
        if (isValid(curr)){
            if (state == OUT) { // start of word
                wc++;
                state = IN;
                putchar('"');  // used for clarity
            } // not shown else clause for within a word
            putchar(curr);
        } else {
            if (state == IN) { // end of word
                putchar('"'); // used for clarity
                putchar('\n');
            } // not shown else clause for between words
            state = OUT;        
        }
    }
    printf("\nwords: %d\n", wc);
}

/*
Count words:
Word is any sequence of characters that doesn;t have blank, tab, or newline
Track wc variable (word count) that starts at 0
Also track previous and current characters
Iterate over each character we receive and continue loop unless it is EOF character
- If current is valid character while previous is invalid or not set, then increment word count
- If current is valid character while previous is valid as well, means still on same word and do nothing
- If current is invalid character while previous is valid, means ended a word and do nothing
- If current is invalid character while previous is invalid as well, means still in between wrods do nothing
*/