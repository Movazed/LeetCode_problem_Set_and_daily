class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 3 == 0) return total;

        vector<int> r1, r2;
        for (int x : nums) {
            if (x % 3 == 1) r1.push_back(x);
            else if (x % 3 == 2) r2.push_back(x);
        }
        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());

        int mod = total % 3;
        int option1 = -1, option2 = -1;
        if (mod == 1) {
            if (!r1.empty()) option1 = total - r1[0];
            if (r2.size() >= 2) option2 = total - (r2[0] + r2[1]);
        } else {
            if (!r2.empty()) option1 = total - r2[0];
            if (r1.size() >= 2) option2 = total - (r1[0] + r1[1]);
        }

        int ans = max(option1, option2);
        return ans < 0 ? 0 : ans;
    }
};