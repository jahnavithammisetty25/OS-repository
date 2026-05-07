#include <stdio.h>

int main() {
    int n, m, i, j, k;
    printf("1BF24CS317\n");

    printf("Processes: ");
    scanf("%d", &n);

    printf("Resources: ");
    scanf("%d", &m);

    int alloc[n][m], req[n][m], avail[m];
    int work[m], finish[n], seq[n];

    printf("Enter Allocation Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&req[i][j]);

    printf("Enter Available Resources:\n");
    for(i=0;i<m;i++) {
        scanf("%d",&avail[i]);
        work[i] = avail[i];
    }

    for(i=0;i<n;i++)
        finish[i] = 0;

    int count = 0;

    while(count < n) {

        int found = 0;

        for(i=0;i<n;i++) {

            if(finish[i] == 0) {

                for(j=0;j<m;j++)
                    if(req[i][j] > work[j])
                        break;

                if(j == m) {

                    for(k=0;k<m;k++)
                        work[k] += alloc[i][k];

                    seq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    if(count == n) {

        printf("\nNo Deadlock\nSafe Sequence: ");

        for(i=0;i<n;i++)
            printf("P%d ", seq[i]);
    }
    else {

        printf("\nDeadlock exists\nDeadlocked processes: ");

        for(i=0;i<n;i++)
            if(finish[i] == 0)
                printf("P%d ", i);
    }

    return 0;
}
