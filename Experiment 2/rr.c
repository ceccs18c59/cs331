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
    int remBurstTime;
};

int calculateWaitingTime(struct Process p[], int limit, int timeSlice)
{

    int totalWaitTime = 0;
    int totalTurnArndTime = 0;
    int t = 0;
    bool done = false;

    while (true)
    {
        done = true;
        for (int i = 0; i < limit; i++)
        {
            if (p[i].remBurstTime > 0)
            {
                done = false;

                if (p[i].remBurstTime > timeSlice)
                {
                    t += timeSlice;
                    p[i].remBurstTime -= timeSlice;
                }
                else
                {
                    t = t + p[i].remBurstTime;
                    p[i].waitTime = t - p[i].burstTime;
                    p[i].remBurstTime = 0;
                }
            }
        }

        if (done == true)
            break;
    }

    for (int i = 0; i < limit; i++)
    {
        p[i].turnArndTime = p[i].waitTime + p[i].burstTime;
        totalWaitTime = totalWaitTime + p[i].waitTime;
        totalTurnArndTime = totalTurnArndTime + p[i].turnArndTime;
    }
    avgTurnArndTime = (float)totalTurnArndTime / limit;
    avgWaitTime = (float)totalWaitTime / limit;

    return t;
};

int display(struct Process p[], int limit, int time)
{

    printf("\n\nID\tBurst Time\tWait Time\tTurn Around Time");
    for (int i = 0; i < limit; i++)
    {
        printf("\n%d\t%d\t\t%d\t\t%d", p[i].id, p[i].burstTime, p[i].waitTime, p[i].turnArndTime);
    }
    printf("\n\nTotal Time Taken: %d", time);
    return 0;
};

int main()
{
    int limit = 0, timeSlice, time;
    printf("Enter No. of Process [MAX: %d]: ", processLimit);
    scanf("%d", &limit);
    printf("Enter time slice(Quantum) of CPU: ", timeSlice);
    scanf("%d", &timeSlice);

    struct Process p[processLimit];
    printf("\n");

    for (int i = 0; i < limit; i++)
    {
        printf("Enter Burst Time of Process %d : ", i + 1);
        scanf("%d", &p[i].burstTime);
        p[i].remBurstTime = p[i].burstTime;
        p[i].id = i + 1;
        p[i].waitTime = 0;
        p[i].turnArndTime = 0;
    }

    time = calculateWaitingTime(p, limit, timeSlice);
    display(p, limit, time);
    printf("\n\nAverage Waiting Time : %0.2f s\n", avgWaitTime);
    printf("Average Turn Around Time : %0.2f s", avgTurnArndTime);
    getch();
    return 0;
};