class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ar = nums;

        ar.insert(ar.end(), nums.begin(), nums.end());

        return ar;
    }
};