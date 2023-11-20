#include <stdio.h>

int main() {
  char str[] = "Testing";
  char *strP = &str;
  char firstChar = str[0];
  char *firstCharP = &str[0];
  char secChar = str[1];
  char *secCharP = &str[1];
  char thirdChar = str[2];
  char *thirdCharP = strP + 2;

  printf("str: %s firstChar: %c secChar: %c thirdChar: %c\n", str, firstChar,
         secChar, thirdChar);
  printf("strP: %p firstCharP: %p secCharP: %p thirdCharP: %p\n", strP,
         firstCharP, secCharP, thirdCharP);

  return 0;
}