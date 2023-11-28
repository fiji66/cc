#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int i, int j) {
    if (i == j)
        return 0;

    int minCost = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = matrixChainOrder(p, i, k) + matrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

        if (cost < minCost)
            minCost = cost;
    }

    return minCost;
}

int main() {
    int n = 4;
    int p[] = {10, 30, 5, 60};

    int result = matrixChainOrder(p, 1, n - 1);

    printf("Minimum number of multiplications is: %d\n", result);

    return 0;
}