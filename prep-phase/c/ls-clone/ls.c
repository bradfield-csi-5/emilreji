#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

void print(struct dirent *dirs[], int size) {
    int idx = 0;
    while(idx < size) {
        struct dirent currDir = *dirs[idx++];
        printf("%s\t", currDir.d_name);
    }
}

struct flags {
    int all;
    int list;
};

struct flags defaultFlags()
{
    struct flags temp;
    temp.all = 0;
    temp.list = 0;
    return temp;
}

struct flags computeFlags(int argc, char *argv[]) {
    struct flags flagData = defaultFlags();
    
    if (argc == 1) {
        return flagData;
    }
    // for (int i = 0; i < argc; i++)
    //     printf("argv[%d] = %s\n", i, argv[i]);
    
    // when running ls a, really get: ls: cannot access 'a': No such file or directory
    // need to change this to real behavior at some point
    if (argv[1][0] != '-') {
       printf("Error: missing - before flag(s).\n"); 
       exit(0);
    }

    int idx = 1;
    char flag;
    
    while((flag = argv[1][idx++]) != '\0') {
        if (flag == 'a') {
            flagData.all = 1;
        }
    }

    return flagData;
}

int main(int argc, char *argv[]) {
    struct flags flagData = computeFlags(argc, argv);

    struct dirent *dirPtr;
    DIR * directory = opendir("./");

    struct dirent *directories[MAX_ENTRIES];
    struct dirent *files[MAX_ENTRIES];
    int directoriesIdx = 0;
    int filesIdx = 0;

    while((dirPtr = readdir(directory)) != NULL) {
        struct dirent currDir = *dirPtr;

        if (strcmp(currDir.d_name, ".") == 0 || strcmp(currDir.d_name, "..") == 0) {
            continue;
        }

        if (currDir.d_type == 8) { // DT_REG is 8 aka a standard file
            files[filesIdx++] = dirPtr;
        } else if (currDir.d_type == 4) { // DT_DIR is 4 aka a directory
            directories[directoriesIdx++] = dirPtr;
        }
    }

    if(flagData.all) {
        printf("\n.\t..\t");
    }

    print(files, filesIdx);
    print(directories, directoriesIdx);
    printf("\n");

    closedir(directory);
}
