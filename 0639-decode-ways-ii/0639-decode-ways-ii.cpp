class Solution {
public:
    const int MOD = 1e9 + 7;

    int rec(int i, string& s, vector<int>& dp, vector<bool>& vis) {
        int n = s.size();
        if (i == n) return 1;
        if (s[i] == '0') return 0;
        if (vis[i]) return dp[i];

        long long ways = 0;

        // Take one character
        if (s[i] == '*')
            ways += (9LL * rec(i + 1, s, dp, vis)) % MOD;
        else
            ways += rec(i + 1, s, dp, vis) % MOD;

        // Take two characters
        if (i + 1 < n) {
            if (s[i] == '*' && s[i + 1] == '*') {
                ways += (15LL * rec(i + 2, s, dp, vis)) % MOD;
            } else if (s[i] == '*') {
                if (s[i + 1] >= '0' && s[i + 1] <= '6')
                    ways += (2LL * rec(i + 2, s, dp, vis)) % MOD;
                else
                    ways += rec(i + 2, s, dp, vis) % MOD;
            } else if (s[i + 1] == '*') {
                if (s[i] == '1')
                    ways += (9LL * rec(i + 2, s, dp, vis)) % MOD;
                else if (s[i] == '2')
                    ways += (6LL * rec(i + 2, s, dp, vis)) % MOD;
            } else {
                int val = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (val >= 10 && val <= 26)
                    ways += rec(i + 2, s, dp, vis) % MOD;
            }
        }

        vis[i] = true;
        return dp[i] = ways % MOD;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        vector<bool> vis(n + 1);
        return rec(0, s, dp, vis);
    }
};