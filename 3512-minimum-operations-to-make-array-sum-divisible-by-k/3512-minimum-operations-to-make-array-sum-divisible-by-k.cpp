#define ll long long

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> n = nums;
        ll sum = 0;
        for(int x : n) sum += x;

        return sum % k;
    }
};