#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_ENTRIES 100

struct flags
{
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

struct flags computeFlags(int argc, char *argv[])
{
    struct flags flagData = defaultFlags();

    if (argc == 1)
    {
        return flagData;
    }
    // for (int i = 0; i < argc; i++)
    //     printf("argv[%d] = %s\n", i, argv[i]);

    // when running ls a, really get: ls: cannot access 'a': No such file or directory
    // need to change this to real behavior at some point
    if (argv[1][0] != '-')
    {
        printf("Error: missing - before flag(s).\n");
        exit(0);
    }

    int idx = 1;
    char flag;

    while ((flag = argv[1][idx++]) != '\0')
    {
        if (flag == 'a')
        {
            flagData.all = 1;
        }
        else if (flag == 'l')
        {
            flagData.list = 1;
        }
        else
        {
            printf("ls: invalid option -- '%c'\n", flag);
            exit(0);
        }
    }

    return flagData;
}

long int fileSize(struct dirent *linePtr)
{
    int statResult;
    struct stat *statbuf;
    statResult = stat((*linePtr).d_name, statbuf);

    // printf("dirent name: %s dirent inode num: %lu\n", (*linePtr).d_name, (*linePtr).d_ino);
    // printf("statbuf st_ino: %lu\n", (*statbuf).st_ino);
    // printf("statbuf st_size: %d\n", (*statbuf).st_size);
    return (*statbuf).st_size;
}

void printLine(struct flags flagData, struct dirent *linePtr)
{
    if (flagData.list)
    {
        long int size = fileSize(linePtr);
        printf("%lu\t%s\n", size, (*linePtr).d_name);
    }
    else
    {
        printf("%s\t", (*linePtr).d_name);
    }
}

void printAll(struct flags flagData, struct dirent *files[], int filesIdx, struct dirent *directories[], int directoriesIdx)
{
    struct dirent currDir;
    if (flagData.all)
    {
        // currDir = *directories[0];
        // printf("%s\t", currDir.d_name);
        printLine(flagData, directories[0]);
        // currDir = *directories[1];
        // printf("%s\t", currDir.d_name);
        printLine(flagData, directories[1]);
    }

    int idx = 0;
    while (idx < filesIdx)
    {
        // currDir = *files[idx++];
        // printf("%s\t", currDir.d_name);
        printLine(flagData, files[idx++]);
    }

    idx = 2;
    while (idx < directoriesIdx)
    {
        // currDir = *directories[idx++];
        // printf("%s\t", currDir.d_name);
        printLine(flagData, directories[idx++]);
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    struct flags flagData = computeFlags(argc, argv);

    struct dirent *dirPtr;
    DIR *directory = opendir("./");

    struct dirent *directories[MAX_ENTRIES];
    struct dirent *files[MAX_ENTRIES];

    int directoriesIdx = 2;
    int filesIdx = 0;

    while ((dirPtr = readdir(directory)) != NULL)
    {
        struct dirent currDir = *dirPtr;

        if (strcmp(currDir.d_name, ".") == 0)
        {
            directories[0] = dirPtr;
        }
        else if (strcmp(currDir.d_name, "..") == 0)
        {
            directories[1] = dirPtr;
        }
        else if (currDir.d_type == 8)
        { // DT_REG is 8 aka a standard file
            files[filesIdx++] = dirPtr;
        }
        else if (currDir.d_type == 4)
        { // DT_DIR is 4 aka a directory
            directories[directoriesIdx++] = dirPtr;
        }
    }

    printAll(flagData, files, filesIdx, directories, directoriesIdx);

    closedir(directory);
}
