#include <stdio.h>
#include <conio.h>

int sortSeq(int p[], int limit)
{
    int pos, temp;
    for (int i = 0; i < limit; i++)
    {
        pos = i;
        for (int j = i; j < limit; j++)
        {
            if (p[j] < p[pos])
                pos = j;
        }
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    return 0;
};

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

    sortSeq(seq, limit);

    printf("\nSorted Sequence : ");
    for (i = 0; i < limit + 1; i++)
        printf("%d ", seq[i]);

    /*
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
    */

    //code
    getch();
}