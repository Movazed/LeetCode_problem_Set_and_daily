// C++17 CP style, line commented
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& a) {
        ios::sync_with_stdio(false); 
        cin.tie(NULL);

        // ans holds total periods, cnt holds current streak length
        long long ans = 0, cnt = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
            if (i > 0 && a[i - 1] - a[i] == 1) {
                // continues smooth descent
                ++cnt;
            } else {
                // new streak starts at this day
                cnt = 1;
            }
            ans += cnt; // add all periods ending at i
        }
        return ans;
    }
};