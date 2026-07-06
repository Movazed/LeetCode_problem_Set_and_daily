#include <algorithm>
#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& A) {
        ranges::sort(
            A,
            {},                         
            [](const auto& x) {         
                return pair{x[0], -x[1]}; 
            }
        );

        int res = 0;
        int r = 0;

        for (const auto& x : A) {
            res += x[1] > r;            
            r = max(r, x[1]);
        }

        return res;
    }
};