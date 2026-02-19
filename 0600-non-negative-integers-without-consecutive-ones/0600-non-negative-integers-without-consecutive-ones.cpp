class Solution {
public:
    vector<int> digit; 
    int dp[32][2][2];

    int dfs(int pos, int tight, int prev) {
        if(pos == (int)digit.size()) return 1;

        int &ans = dp[pos][tight][prev];
        if(ans != -1) return ans;

        ans = 0;
        int range = tight ? digit[pos] : 1;

        for(int d=0; d<=range; d++) {
            
            if(d == 1 && prev == 1) continue;
            int nextTight = tight && (d == range);
            int nextPrev = d;

            ans += dfs(pos+1, nextTight, nextPrev);
        }

        return ans;
    }

    int can(string num) {
        for(auto &i : num) {
            digit.push_back(i - '0');
        }

        memset(dp, -1, sizeof(dp));

        return dfs(0, 1, 0);
    }

    int findIntegers(int n) {
        //best way to solve > convert n to binary, form all less<=that binary 
        //32 bit position, 2 bit for tight, 2 for previos element

        string num = "";
        while(n) {
            num += to_string(n%2);
            n /= 2;
        }

        reverse(num.begin(), num.end());

        return can(num);
    }
};