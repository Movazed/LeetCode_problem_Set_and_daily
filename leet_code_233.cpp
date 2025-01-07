#include<bits/stdc++.h>
#define vi vector<int>
#define leftside (node->left)
#define rightside (node->right)
#define LOOP(i , s) for(ll i = 0; i < (s); ++i)
typedef long long ll;
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


class Solution {
public:
    ll countDigitOne(ll n) {
        if(n <= 0){
            return 0;
        }
        ll ones = 0;
        for(ll m = 1; m <= n; m *= 10){
            ones += (n / m + 8) / 10 * m + (n/m % 10 == 1) * (n%m + 1);
        }
        return ones;

    }
};