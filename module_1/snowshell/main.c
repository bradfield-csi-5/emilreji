#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LINE_LEN    10
// when input line exceeds this value, only shows stack smashing detected error when ctrl + D used
// output itself is fine until ctrl + D is used

int handleCommand(char *cmd) {
    printf("%s", cmd);
    char *argv[1];
    argv[0] = &cmd;
    pid_t childProcess = fork();
    execl(cmd, argv);
    kill(childProcess);
}

int main() {
    // https://stackoverflow.com/questions/43834315/printing-a-unicode-symbol-in-c
    // while(1) {
    //     char prompt = '>'; // change to snowman once I review class 2 content
    //     printf("%lc", prompt);
    //     char input[MAX_LINE_LEN];
    //     scanf("%s", &input);
    //     if (input[0] == EOF) {
    //         printf("❄❅❄❅ Goodbye and stay warm! ❄❅❄❅\n");
    //         exit(0);
    //     }
    //     printf("%s\n", &input);
    // }

    int currChar;
    char currLine[MAX_LINE_LEN];

    char prompt = '>';
    int i = 0;
    putchar(prompt);

    while((currChar = getchar()) != EOF) {
        currLine[i] = currChar;
        i++;
        if (i >= MAX_LINE_LEN) {
            printf("\n❄❅❄❅ Exceeded max line length of %d. Exiting early. ❄❅❄❅\n", MAX_LINE_LEN);
            exit(1);
        }
        if (currChar == '\n') {
            currLine[i] = '\0';
            handleCommand(currLine);
            // printf("%s", currLine);
            putchar(prompt);
            i = 0;
        }
    }
    printf("^D\n❄❅❄❅ Goodbye and stay warm! ❄❅❄❅\n");
    exit(0);
}
// seems to need 2 ctrl + D's when exiting after having already typed something on current line
// only need 1 ctrl + D when on new line and haven't typed anything yet

/*
Print out snowman and then wait
User enters some data
That data is then outputted

*/