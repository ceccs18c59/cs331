#include <stdio.h>
#include <conio.h>

void main()
{
    int seq[20], i, seekTime = 0, limit;
    int direction;

    printf("Enter lenght of Sequence: ");
    scanf("%d", &limit);

    printf("Enter the Sequence [%d]: ", limit);
    for (i = 0; i < limit; i++)
        scanf("%d", &seq[i + 1]);

    printf("Enter initial head position: ");
    scanf("%d", &seq[0]);

    printf("Enter the Direction (Right 0, Left 1): ");
    scanf("%d", &direction);

    switch (direction)
    {
    case 1:
        printf("Left Direction");
        break;

    case 0:
        printf("rigjt");
        break;
    default:
        break;
    }

    //code
    getch();
}