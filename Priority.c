#include <stdio.h>
#include <string.h>

struct Process
{
    char pid[10];
    int at;
    int bt;
    int pr;
    int wt;
    int tat;
    int completed;
};

int main()
{
    int n;
    scanf("%d",&n);

    struct Process p[n];

    for(int i=0;i<n;i++)
    {
        scanf("%s %d %d %d",p[i].pid,&p[i].at,&p[i].bt,&p[i].pr);
        p[i].completed=0;
    }

    int time=0,done=0;
    float total_wt=0,total_tat=0;

    while(done<n)
    {
        int idx=-1;
        int best_pr=9999;

        for(int i=0;i<n;i++)
        {
            if(p[i].at<=time && p[i].completed==0)
            {
                if(p[i].pr < best_pr)
                {
                    best_pr=p[i].pr;
                    idx=i;
                }
                else if(p[i].pr==best_pr)
                {
                    if(p[i].at < p[idx].at)
                    idx=i;
                }
            }
        }

        if(idx==-1)
        {
            time++;
            continue;
        }

        p[idx].wt = time - p[idx].at;
        time += p[idx].bt;
        p[idx].tat = p[idx].wt + p[idx].bt;

        p[idx].completed=1;
        done++;

        total_wt += p[idx].wt;
        total_tat += p[idx].tat;
    }

    printf("Waiting Time:\n");
    for(int i=0;i<n;i++)
        printf("%s %d\n",p[i].pid,p[i].wt);

    printf("Turnaround Time:\n");
    for(int i=0;i<n;i++)
        printf("%s %d\n",p[i].pid,p[i].tat);

    printf("Average Waiting Time: %.2f\n",total_wt/n);
    printf("Average Turnaround Time: %.2f\n",total_tat/n);

    return 0;
}
