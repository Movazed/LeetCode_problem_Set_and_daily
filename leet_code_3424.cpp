#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>    
class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        ll len = arr.size();
        vi tmp = arr;
        vi dst = brr;

        ll raw = 0;

        for(int i = 0; i < len; i++){
            raw = raw + abs(1LL * arr[i] - brr[i]);
        }

        sort(tmp.begin(), tmp.end());
        sort(dst.begin(), dst.end());

        ll srt = k;
        for(ll i = 0; i < len; i++){
            srt += abs(1LL * tmp[i] - dst[i]);
        }

        return min(raw, srt);
    }
};