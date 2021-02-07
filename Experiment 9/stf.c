#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct SYM_TAB
{
    char LABEL_NAME[10];
    char SYMBOL[10];
    int ADDRESS;
    struct SYM_TAB *next;
};

int SIZE = 0;
struct SYM_TAB *first, *last;

int searchTab(char LABEL_NAME[10])
{
    int i = 0, flag = 0;
    struct SYM_TAB *p;
    p = first;

    for (i = 0; i < SIZE; i++)
    {
        if (strcmp(p->LABEL_NAME, LABEL_NAME) == 0)
        {
            flag = 1;
            break;
        }
        else
            p = p->next;
    }

    return flag;
};

void insertTab()
{
    int n;
    char temp[10];
    printf("\nEnter the label: ");
    scanf("%s", temp);

    if (searchTab(temp) == 0)
    {
        struct SYM_TAB *p;
        p = malloc(sizeof(struct SYM_TAB));
        strcpy(p->LABEL_NAME, temp);
        printf("Enter Symbol :");
        scanf("%s", p->SYMBOL);
        printf("Enter ADDRESS :");
        scanf("%d", &p->ADDRESS);

        if (SIZE == 0)
        {
            first = p;
            last = p;
        }
        else
        {
            last->next = p;
            last = p;
        }
        SIZE++;
    }
    else
        printf("\n\tThe label exists already in the symbol table\n\tDuplicate can’t be inserted");
}

void main()
{
    int opt;
    while (1)
    {
        printf("\n 1) Insert \nEnter Choice: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            insertTab();
            break;
        }
    }
}