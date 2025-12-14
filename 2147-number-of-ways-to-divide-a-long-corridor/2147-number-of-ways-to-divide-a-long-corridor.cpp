class Solution {
public:
    int numberOfWays(string s) {
        const long long mod = 1e9 + 7;
        vector<int> seatIdx;
        for(int i = 0; i < s.size(); ++i)
            if(s[i] == 'S') seatIdx.push_back(i);
        
        int n = seatIdx.size();
        if(n == 0 || n % 2 == 1) return 0; // invalid if no seats or odd number
        
        long long res = 1;
        for(int i = 2; i < n; i += 2) {
            int left = seatIdx[i - 1];
            int right = seatIdx[i];
            res = (res * (right - left)) % mod;
        }
        return res;
    }
};