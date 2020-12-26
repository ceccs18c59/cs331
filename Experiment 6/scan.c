#include <stdio.h>
#include <conio.h>
#include <math.h>

int sortSeq(int seq[], int limit)
{
    int pos, temp;
    for (int i = 0; i < limit; i++)
    {
        pos = i;
        for (int j = i; j < limit; j++)
        {
            if (seq[j] < seq[pos])
                pos = j;
        }
        temp = seq[i];
        seq[i] = seq[pos];
        seq[pos] = temp;
    }
    return 0;
};

int findIndex(int seq[], int limit, int head)
{
    for (int i = 0; i < limit; i++)
        if (head == seq[i])
        {
            seq[i] = 0;
            return i;
            break;
        }
}
int seeker(int seq[], int limit, int head, int direction, int init)
{
    int count = 0, j = 0, i, seqL[20], seekTime = 0;
    int run = 2;
    while (run--)
    {
        if (direction == 0)
        {
            for (int i = head - 1; i >= 0; i--)
            {
                seqL[count] = seq[i];
                printf("%d ", seq[i]);
                count++;
            }
            direction = 1;
        }
        else if (direction == 1)
        {
            for (int i = head; i <= limit; i++)
            {
                seqL[count] = seq[i];
                printf("%d ", seq[i]);
                count++;
            }
            direction = 0;
        }
    }
    seekTime = init - seqL[0];
    for (int i = 0; i < limit; i++)
        seekTime = seekTime + abs(seqL[i] - seqL[i + 1]);
    printf("\n Total Seek Time : %d", seekTime);
    return 0;
}

void main()
{
    int seq[20], seqL[20], i, j, seekTime = 0, limit, init;
    int direction;

    printf("Enter lenght of Sequence: ");
    scanf("%d", &limit);

    printf("Enter the Sequence [%d]: ", limit);
    for (i = 0; i < limit; i++)
        scanf("%d", &seq[i + 1]);

    printf("Enter initial head position: ");
    scanf("%d", &init);

    seq[0] = init;

    sortSeq(seq, limit + 1);
    int head = findIndex(seq, limit + 1, init);

    // 0 = left, 1 = right
    printf("\nSeek Sequence: ");
    seeker(seq, limit, head, 0, init);

    getch();
}