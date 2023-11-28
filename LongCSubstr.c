#include <stdio.h>
#include <string.h>

int longestCommonSubstring(char *X, char *Y, int m, int n) {
    int dp[m + 1][n + 1];
    int result = 0; 

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                result = (result > dp[i][j]) ? result : dp[i][j];
            } 
            else
                dp[i][j] = 0;
        }
    }

    return result;
}

int main() {
    char X[] = "ABABC";
    char Y[] = "BABCAC";

    int m = strlen(X);
    int n = strlen(Y);

    int length = longestCommonSubstring(X, Y, m, n);

    printf("Length of Longest Common Substring: %d\n", length);

    return 0;
}
