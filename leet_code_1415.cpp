#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string getHappyString(int n, int k) {
            const int m = 3 << (n - 1);
            if (m < k) return "";
            int t[3][2] = {{1, 2}, {0, 2}, {0, 1}};
            string s(n, 'a');
            s[0] += (k > m / 3) + (k > 2 * m / 3);
            --k;
            for (int i = 1; i < n; ++i)
                s[i] += t[s[i - 1] - 97][(k & (1 << (n - i - 1))) > 0];
            return s;
        }
    };