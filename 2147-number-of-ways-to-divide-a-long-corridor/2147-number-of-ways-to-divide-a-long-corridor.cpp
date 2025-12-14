#define vi vector<int>
#define ll long long
const int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfWays(string corridor) {
        string cor = corridor;
        vi si;
        for(int i = 0; i < cor.length(); ++i){
            if(cor[i] == 'S'){
                si.push_back(i);
            }

        }
        ll ns = si.size();


        if(ns == 0 || ns % 2 != 0){
            return 0;
        }

        ll res = 1;

        for(int j = 1; j < ns - 1; j += 2){
            int ind2 = si[j];

            int ind2p1 = si[j + 1];

            ll gp = ind2p1 - ind2;
            res = (res * gp) % MOD;
        }

        return (int)res;
    }
};