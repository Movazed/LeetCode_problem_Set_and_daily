class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> freq;

        for(int num : nums){
            freq[num]++;
        }

        for(const auto& [val1, val1_cnt] : freq) {
            int val2 = k - val1;

            if(val1 < val2 || freq.find(val2) == freq.end()){
                continue;
            }

            if(val1 != val2){
                res += min(val1_cnt, freq[val2]);
            }
            else {
                res += val1_cnt / 2;
            }
        }
        return res;
    }
};