#include <stdio.h>
/*
Take in multiple lines and iterate over them
Output a given line if it contains a set pattern
*/

#define LINE_LENGTH 100
/*
Iterate over s until first current character of s matches first character of t
If that matches, iterate over t and compare next
*/
int strindex(char s[], char t[]) {
  char sCharIdx;
  char tCharIdx;
  int found = 0;

  for (sCharIdx = 0; s[sCharIdx] != '\0'; sCharIdx++) {
    if (s[sCharIdx] == t[0]) {
      found = 1;
      int sCharInnerIdx = sCharIdx;
      for (tCharIdx = 0; t[tCharIdx] != '\0'; tCharIdx++, sCharInnerIdx++) {
        // printf("Comparing: indexes: %d %d chars: %c %c\n", sCharInnerIdx,
        //    tCharIdx, t[tCharIdx], s[sCharInnerIdx]);
        if (t[tCharIdx] != s[sCharInnerIdx]) {
          found = 0;
          break;
        }
      }

      if (found) {
        return sCharIdx;
      }
    }
  }

  return -1;
}

int getLine(char s[], int lim) { // can't use getline since conflicts
  int c, currLen, i;
  currLen = 0;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
    currLen++;
  }
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';

  return i;
}

int main() {
  char line[LINE_LENGTH];
  char pattern[] = "ould";
  int idx;

  while (getLine(line, LINE_LENGTH)) {
    if ((idx = strindex(line, pattern)) != -1) {
      printf("%s\n", line);
    }
    // printf("%d\n", idx);
  }

  //   char str[] = "would";
  //   char pattern[] = "ould";

  //   int result = strindex(str, pattern);
  //   printf("Result index: %d\n", result);
}