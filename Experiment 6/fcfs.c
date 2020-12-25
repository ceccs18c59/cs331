#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
    int seq[20], i, seekTime = 0, limit;

    printf("Enter lenght of Sequence: ");
    scanf("%d", &limit);

    printf("Enter the Sequence [%d]: ", limit);
    for (i = 0; i < limit; i++)
        scanf("%d", &seq[i + 1]);

    printf("Enter initial head position: ");
    scanf("%d", &seq[0]);

    for (int i = 0; i < limit; i++)
    {
        seekTime = seekTime + abs(seq[i + 1] - seq[i]);
    }
    printf("\nTotal Seek Time is : %d ", seekTime);

    getch();
}
