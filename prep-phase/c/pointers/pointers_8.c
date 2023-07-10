#include <stdio.h>

int main(){
    char amessage[] = "now is the time"; /* an array */
    char *pmessage = "now is the time"; /* a pointer */

    printf("'%s'\n", amessage);
    printf("'%s'\n\n", pmessage);

    amessage[4] = 'a';
    printf("'%s'\n", amessage);
    printf("'%s'\n\n", pmessage);
    // amessage is an array so can change individual characters

    // amessage = {};
    // expression must be a modifiable lvalue
    // amessage is an array so we can't reassign it to another array

    // pmessage[4] = 'a';
    // Segmentation fault (core dumped)
    // because pmessage is a pointer to an character array which is a string constant, can't modify contents

    char *charPtr = "charPtr";
    pmessage = charPtr;

    printf("'%s'\n", amessage);
    printf("'%s'\n\n", pmessage);
    // 'charPtr'
    // pemessage is a pointer to any character array and thus can be reassigned to another one
}