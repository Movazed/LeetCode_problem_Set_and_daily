class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0, cr = 0;

        for(int x : nums){
            if(x == 1){
                cr++;
                mx = max(mx, cr);
            } else {
                cr = 0;
            }
        }

        return mx;
    }
};