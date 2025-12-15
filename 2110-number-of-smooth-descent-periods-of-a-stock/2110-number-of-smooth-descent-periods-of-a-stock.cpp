class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        
        long long ans = 1, cnt = 1;
        for (int i = 1; i < p.size(); ++i) {
            if (p[i-1] - p[i] == 1) cnt++;
            else cnt = 1;
            ans += cnt;
        }
        return ans;
    }
};