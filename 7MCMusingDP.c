#include <stdio.h>
#include <limits.h>

int matrixChainMultiplication(int dims[], int n) {
    int dp[n][n];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int dims[] = {40,20,30,10,30};
    int n = sizeof(dims) / sizeof(dims[0]);

    int result = matrixChainMultiplication(dims, n);

    printf("Minimum number of scalar multiplications: %d\n", result);

    return 0;
}