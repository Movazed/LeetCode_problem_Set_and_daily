class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        long long res = 1, streak = 1;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i - 1] - prices[i] == 1) streak++;
            else streak = 1;
            res += streak;
        }
        return res;
    }
};