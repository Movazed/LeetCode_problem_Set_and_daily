class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if (n == 0) return res;

        sort(nums.begin(), nums.end());

        int expected = 1;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (x < expected) continue;        // skip duplicates or numbers smaller than expected
            while (expected < x) {
                res.push_back(expected);      // expected is missing
                ++expected;
            }
            if (expected == x) ++expected;    // consume this number
        }
        while (expected <= n) {               // remaining numbers after the largest element
            res.push_back(expected++);
        }
        return res;
    }
};