#include <stdio.h>
int main()
{
    int n;
    int AT[100], PT[100], W[100], TAT[100], WT[100];
    while (1)
    {

        printf("Enter the number of processes\n");
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            printf("Enter  burst time(processing time) for process %d ", i);
            scanf("%d", &PT[i]);
            printf("Enter Arrival time for process %d ", i);
            scanf("%d", &AT[i]);
        }
        // arraywaiting
        W[0] = PT[0];
        for (int i = 1; i < n; i++)
        {
            W[i] = W[i - 1] + PT[i];
        }

        for (int i = 0; i < n; i++)
        {
            TAT[i] = W[i] - AT[i];
        }

        for (int i = 0; i < n; i++)
        {
            WT[i] = TAT[i] - PT[i];
        }

        for (int i = 0; i < n; i++)
        {
            printf(" TAT of process %d is = %d \n", i, TAT[i]);
            printf(" WT of process %d is= %d \n", i, WT[i]);
        }
        float ATAT = 0;
        for (int i = 0; i < n; i++)
        {
            ATAT = ATAT + TAT[i];
        }
        ATAT = ATAT / n;
        printf("Average ATAT=%f\n", ATAT);
    }
    return 0;
}
