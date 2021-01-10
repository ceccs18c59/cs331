#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct Directory
{
    int nof, nod;
    char dirName[10];
    char *files[10];
    struct Directory *dirs[10];
};

void createDir(struct Directory *d)
{
    struct Directory *node;

    node = malloc(sizeof(struct Directory));
    node->nod = 0;
    node->nof = 0;
    printf("Enter Directory name: ");
    scanf("%s", node->dirName);

    d->dirs[d->nod] = node;
    d->nod++;
}

void add(struct Directory *d)
{
    char temp[10];
    printf("Enter file Name: ");
    scanf("%s", temp);
    d->files[d->nof] = temp;
    d->nof++;
}

void display(struct Directory *d, int dl, int fl)
{
}

void main()
{
    struct Directory *root, *curr;

    //Initializing ROOT
    root = malloc(sizeof(struct Directory));
    strcpy(root->dirName, "ROOT");
    root->nod = 0;
    root->nof = 0;
    for (int i = 0; i < 10; i++)
        root->files[i] = (char *)malloc(10 * sizeof(char));

    printf("1.Change Directory   2.Create Directory   3.Create A Filet   4.Display   5.Exit\n\nEnter Choice : ");
    createDir(root);
    add(root);

    printf("%s", root->files[0]);

    getch();
}
