#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

int main()
{
    int nof;
    int memory[50];
    int status, firstBlock, blockSize, j;
    char c = 'y';

    // Initalize Memory Blocks
    for (int i = 0; i < 50; i++)
        memory[i] = 0;
    for (; c == 'Y' || c == 'y';)
    {

        printf("\nEnter the starting block & length of file : ");
        scanf("%d %d", &firstBlock, &blockSize);
        for (j = firstBlock; j < (firstBlock + blockSize); j++)
            if (memory[j] == 0)
            {
                memory[j] = 1;
                printf("\n[%d->%d]", j, memory[j]);
            }
            else
            {
                printf("Block already allocated");
                break;
            }
        if (j == (firstBlock + blockSize))
            printf("\nThe file is allocated to disk");
        printf("\n\nDo you want to enter more files?(Y/N)");
        c = getch();
    }
    getch();
    return 0;
}
