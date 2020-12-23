#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int fileHandler(char dirName[], char *fileNames[], int *nof)
{

    int c, opt;
    char temp[10];
    int flag;

    printf("\n 1.Create File, 2.Delete File, 3.Display Files, 4.Exit");
    printf("\n\tEnter Choice: ");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        flag = 1;
        printf("Enter file name : ");
        scanf("%s", temp);
        if (*nof == 0)
        {
            fileNames[*nof] = (char *)malloc(10);
            strcpy(fileNames[*nof], temp);
            *nof += 1;
            printf("File added!");
            break;
        }

        for (int i = 0; i < *nof; i++)
            if (strcmp(temp, fileNames[i]) == 0)
                flag = 0;
        if (flag == 1)
        {
            fileNames[*nof] = (char *)malloc(10);
            strcpy(fileNames[*nof], temp);
            *nof += 1;
            printf("File added!");
        }
        else
        {
            printf("The file '%s' already exists.\n", temp);
        }
        break;
    case 2:
        flag = -1;
        printf("Enter file name: ");
        scanf("%s", temp);
        for (int i = 0; i < *nof; i++)
        {
            if (strcmp(temp, fileNames[i]) == 0)
                flag = i;
        }
        if (flag == -1)
        {
            printf("No file found!");
            break;
        }
        else
        {
            *nof -= 1;
            for (int i = flag; i < *nof; i++)
                strcpy(fileNames[i], fileNames[i + 1]);
            printf("file Deleted");
        }
        break;
    case 3:
        printf("\nCurrent Directory : %s [%d Files]", dirName, *nof);
        for (int i = 0; i < *nof; i++)
            printf("\n\t\t     |--> %s ", fileNames[i]);
        printf("\n");
        break;

    case 4:
        exit(0);
    default:
        exit(0);
        break;
    }

    fileHandler(dirName, fileNames, nof);
    return 0;
}

int main()
{
    int nof = 0;
    char dirName[10];
    char *fileNames[10];
    printf("Enter Directory Name: ");
    gets(dirName);
    fileHandler(dirName, fileNames, &nof);
    getch();
    return 0;
}