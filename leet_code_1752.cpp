#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        auto pivot = is_sorted_until(nums.begin(), nums.end());
        if (pivot == nums.end()) {
            return true;
        }

        if (is_sorted(pivot, nums.end()) && nums.back() <= nums.front()) {
            return true;
        }
                return false;
    }
};