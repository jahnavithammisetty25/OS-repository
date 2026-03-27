#include <stdio.h>
#include <math.h>

#define MAX 10

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int find_lcm(int arr[], int n) {
    int res = arr[0];
    for (int i = 1; i < n; i++) {
        res = lcm(res, arr[i]);
    }
    return res;
}

int main() {
    printf("1BF24CS317\nR");
    int n, C[MAX], P[MAX], remaining[MAX] = {0};
    int hyperperiod;
    float utilization = 0.0;

    printf("Enter the number of processes:");
    scanf("%d", &n);

    printf("\nEnter the CPU burst times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &C[i]);
    }

    printf("\nEnter the time periods:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &P[i]);
    }

    hyperperiod = find_lcm(P, n);
    printf("\nLCM=%d\n\n", hyperperiod);

    printf("Rate Monotone Scheduling:\n\n");
    printf("PID\tBurst\tPeriod\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, C[i], P[i]);
    }


    for (int i = 0; i < n; i++) {
        utilization += (float)C[i] / P[i];
    }

    float bound = n * (pow(2, 1.0/n) - 1);

    printf("\n%f <= %f => %s\n",
           utilization, bound,
           (utilization <= bound) ? "true" : "false");

    printf("Scheduling occurs for %d ms\n\n", hyperperiod);

    int prev_task = -1;

    for (int t = 0; t < hyperperiod; t++) {


        for (int i = 0; i < n; i++) {
            if (t % P[i] == 0) {
                remaining[i] = C[i];
            }
        }
        int task = -1;
        int minP = 9999;

        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0 && P[i] < minP) {
                minP = P[i];
                task = i;
            }
        }

        if (task != prev_task) {
            if (task == -1)
                printf("%dms onwards: CPU is idle\n", t);
            else
                printf("%dms onwards: Process %d running\n", t, task + 1);
        }
        if (task != -1) {
            remaining[task]--;
        }

        prev_task = task;
    }

    return 0;
}
