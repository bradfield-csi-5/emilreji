#include <stdio.h>

/*
keep track of prev value
if curr value is space and prev value is space, skip outputting curr
if curr value isn't space and prev value is space, output curr
if curr value is space and prev value isn't space, output curr
if curr value isn't space and prev value isn't space. output curr
*/

int main() {
    int c, p;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (p != ' ')  {
                putchar(c);
            }
        } else {
            putchar(c);
        }
        p = c;
    }
}