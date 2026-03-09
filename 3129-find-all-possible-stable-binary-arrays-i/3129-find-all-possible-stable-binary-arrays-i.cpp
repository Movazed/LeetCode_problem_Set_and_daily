class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        long long MOD = 1e9 + 7;
        long long dp[205][205][2];
        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                dp[i][j][0] = dp[i][j][1] = 0;
            }
        }
        dp[0][0][0] = dp[0][0][1] = 1;
        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                if (i == 0 && j == 0) continue;
                for (int k = 1; k <= limit; k++) {
                    if (i - k >= 0) {
                        dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % MOD;
                    }
                    if (j - k >= 0) {
                        dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % MOD;
                    }
                }
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};