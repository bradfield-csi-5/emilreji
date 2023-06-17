#include <stdio.h>

int isValid(c) {
    return c != ' ' && c != '\t' && c != '\n';
}

int main() {
    int wc, prev, curr;
    wc = 0;
    prev = ' ';
    while((curr = getchar()) != EOF) {
        if (isValid(curr) && !isValid(prev)){
            wc++;
        }
        prev = curr;
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

Compared to Solution:
Mine uses two pointer method of prev and curr characters
As a result, need the hack of setting prev to an invalid character to ensure first word is counted

Solution uses state variable which seems to handle this issue without the hack
Start with state set to OUT
When current character is valid and state is OUT (meaning previous was invalid), 
state is set to IN and wc incremented

*/

// optimized version:
/*
int main() {
    int wc, state, curr;
    wc = 0;
    state = OUT;

    while((curr = getchar()) != EOF) {
        if (isValid(curr)){
            if (state == OUT) {
                wc++;
                state = IN;
            }
        } else {
            state = OUT;        
        }
    }
    printf("\nwords: %d\n", wc);
}
*/
