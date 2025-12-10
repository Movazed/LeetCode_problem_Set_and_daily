#define ll long long
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        vector<int> comp = complexity;
        const int c0 = complexity[0],c1 = *min_element(comp.begin() + 1, comp.end()),mod = 1e9 + 7, n=comp.size();

        if(c0 >= c1) return 0;
        ll cnt = 1;

        for(int i = 1; i <= n - 1; i++){
            cnt *= i;
            if(cnt >= mod) cnt%=mod;
        }
        return cnt;
    }
};