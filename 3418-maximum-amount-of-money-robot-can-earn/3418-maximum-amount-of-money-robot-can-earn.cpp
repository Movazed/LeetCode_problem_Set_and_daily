#define ll long long
#define vvvi std::vector<std::vector<std::vector<int>>>
#define vvi std::vector<std::vector<int>>
#define vi std::vector<int>
#define UPDATE_DP_RIGHT(dp, coins, i, j, k) \
    if (coins[i][j] >= 0) {                 \
        dp[i][j][k] = std::max(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]); \
    } else {                                \
        dp[i][j][k] = std::max(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]); \
    }                                       \
    if (k < 2 && coins[i][j]< 0){         \
        dp[i][j][k + 1] = std::max(dp[i][j][k + 1], dp[i][j - 1][k]);       \
    }
#define UPDATE_DP_DOWN(dp, coins, i, j, k)  \
    if (coins[i][j] >= 0) {                 \
        dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]); \
    } else {                                \
        dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]); \
    }                                       \
    if (k < 2 && coins[i][j]< 0) {         \
        dp[i][j][k + 1] = std::max(dp[i][j][k + 1], dp[i - 1][j][k]);       \
    }
#define UPDATE_DP_FIRST_COL(dp, coins, i, k) \
    if (coins[i][0] >= 0) {                  \
        dp[i][0][k] = std::max(dp[i][0][k], dp[i - 1][0][k] + coins[i][0]); \
    } else {                                 \
        dp[i][0][k] = std::max(dp[i][0][k], dp[i - 1][0][k] + coins[i][0]); \
    }                                        \
    if (k < 2 && coins[i][0]< 0) {          \
        dp[i][0][k + 1] = std::max(dp[i][0][k + 1], dp[i - 1][0][k]);       \
    }
#define INITIALIZE_DP(dp, coins) \
    dp[0][0][0] =coins[0][0];   \
    if (coins[0][0] < 0) {       \
        dp[0][0][1] = 0;         \
    }
class Solution {
public:
    int maximumAmount(std::vector<std::vector<int>>& coins) {
        ll m = coins.size();
        ll n = coins[0].size();

        vvvi dp(m, vvi(n, vi(3, INT_MIN)));

        INITIALIZE_DP(dp, coins);

        ll j = 1;
        while (j < n) {
            ll k = 0;
            while (k <= 2) {
                if (dp[0][j - 1][k] != INT_MIN) {
                    UPDATE_DP_RIGHT(dp, coins, 0, j, k);
                }
                k++;
            }
            j++;
        }

        int i = 1;
        while (i < m) {
            int k = 0;
            while (k <= 2) {
                if (dp[i - 1][0][k] != INT_MIN) {
                    UPDATE_DP_FIRST_COL(dp, coins, i, k);
                }
                k++;
            }
            i++;
        }

        i = 1;
        while (i < m) {
            j = 1;
            while (j < n) {
                int k = 0;
                while (k <= 2) {
                    if (dp[i][j - 1][k] != INT_MIN) {
                        UPDATE_DP_RIGHT(dp, coins, i, j, k);
                    }
                    if (dp[i - 1][j][k] != INT_MIN) {
                        UPDATE_DP_DOWN(dp, coins, i, j, k);
                    }
                    k++;
                }
                j++;
            }
            i++;
        }

        int result = INT_MIN;
        int k = 0;
        while (k <= 2) {
            result = std::max(result, dp[m - 1][n - 1][k]);
            k++;
        }

        return result;
    }
};