// C++17 CP style. Binary search + greedy check with diff array
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    #define all(x) (x).begin(), (x).end()

    // build base window sums using prefix
    static vector<ll> buildBase(const vector<int>& st, int r){
        int n = (int)st.size();
        vector<ll> pref(n + 1, 0);
        for(int i = 0; i < n; ++i) pref[i + 1] = pref[i] + st[i];
        vector<ll> base(n, 0);
        for(int i = 0; i < n; ++i){
            int L = max(0, i - r);
            int R = min(n - 1, i + r);
            base[i] = pref[R + 1] - pref[L];
        }
        return base;
    }

    static bool canMake(const vector<ll>& base, int r, long long k, long long mid){
        int n = (int)base.size();
        vector<ll> diff(n, 0);          // where we placed extra stations
        ll addRun = 0;                   // rolling added power affecting i
        ll used = 0;
        for(int i = 0; i < n; ++i){
            if(i - r - 1 >= 0) addRun -= diff[i - r - 1]; // coverage expired
            ll cur = base[i] + addRun;
            if(cur < mid){
                ll need = mid - cur;
                used += need;
                if(used > k) return false;
                int pos = min(n - 1, i + r);
                diff[pos] += need;       // it will cover from i through pos + r
                addRun += need;          // starts helping now
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        vector<ll> base = buildBase(stations, r);
        ll lo = 0, hi = 0;
        for(ll v : base) hi = max(hi, v);
        hi += k;                          // safe upper cap

        ll ans = 0;
        while(lo <= hi){
            ll mid = lo + ((hi - lo) >> 1);
            if(canMake(base, r, k, mid)){
                ans = mid;
                lo = mid + 1;
            }else hi = mid - 1;
        }
        return ans;
    }
};