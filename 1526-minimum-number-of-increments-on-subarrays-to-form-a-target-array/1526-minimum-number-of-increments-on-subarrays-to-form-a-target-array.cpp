// C++17. O(n) time. O(1) extra space.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& a) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        long long ans = 0;                 // total operations
        int n = (int)a.size();
        int prev = 0;                      // previous target value

        for (int i = 0; i < n; ++i) {
            int need = a[i] - prev;        // extra increments starting at i
            if (need > 0) ans += need;     // add only positive rise
            prev = a[i];                   // update previous
        }
        return (int)ans;
    }
};