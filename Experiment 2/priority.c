#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

const int processLimit = 10;
float avgWaitTime;
float avgTurnArndTime;

struct Process
{
    int id;
    int burstTime;
    int waitTime;
    int turnArndTime;
    int priority;
};

int sortProcesses(struct Process p[], int limit)
{
    int pos;
    struct Process temp;
    for (int i = 0; i < limit; i++)
    {
        pos = i;
        for (int j = i + 1; j < limit; j++)
        {
            if (p[j].priority < p[pos].priority)
                pos = j;
        }
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    return 0;
};

int calculateWaitingTime(struct Process p[], int limit)
{

    int totalWaitTime = 0;
    int totalTurnArndTime = 0;
    p[0].waitTime = 0;
    for (int i = 1; i < limit; i++)
    {
        p[i].waitTime = p[i - 1].waitTime + p[i - 1].burstTime;
    }
    for (int i = 0; i < limit; i++)
    {
        p[i].turnArndTime = p[i].waitTime + p[i].burstTime;
    }
    for (int i = 0; i < limit; i++)
    {
        totalWaitTime = totalWaitTime + p[i].waitTime;
        totalTurnArndTime = totalTurnArndTime + p[i].turnArndTime;
    }
    avgTurnArndTime = (float)totalTurnArndTime / limit;
    avgWaitTime = (float)totalWaitTime / limit;

    return 0;
};

int display(struct Process p[], int limit)
{

    printf("\n\nID\tBurst Time\tWait Time\tTurn Around Time");
    for (int i = 0; i < limit; i++)
    {
        printf("\n%d\t%d\t\t%d\t\t%d", p[i].id, p[i].burstTime, p[i].waitTime, p[i].turnArndTime);
    }
    return 0;
};

int main()
{
    int limit = 0, timeSlice, time;
    printf("Enter No. of Process [MAX: %d]: ", processLimit);
    scanf("%d", &limit);

    struct Process p[processLimit];
    printf("\n");

    for (int i = 0; i < limit; i++)
    {
        printf("Enter Burst Time of Process & Priority %d : ", i + 1);
        scanf("%d %d", &p[i].burstTime, &p[i].priority);
        p[i].id = i + 1;
        p[i].waitTime = 0;
        p[i].turnArndTime = 0;
    }
    sortProcesses(p, limit);
    calculateWaitingTime(p, limit);
    display(p, limit);
    printf("\n\nAverage Waiting Time : %0.2f s\n", avgWaitTime);
    printf("Average Turn Around Time : %0.2f s", avgTurnArndTime);
    getch();
    return 0;
};