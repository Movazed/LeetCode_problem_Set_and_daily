#include <bits/stdc++.h>
using namespace std;

void compute(auto& nums, auto& res, auto&& cmp, bool reverse) {
    int n = nums.size();
    vector<int> stk;
    for(int i = reverse ? n-1 : 0; 0 <= i && i < n; reverse ? i-- : i++) {
        while(!stk.empty() && cmp(nums[i], nums[stk.back()])) {
            res[stk.back()] = i;
            stk.pop_back();
        }
        stk.push_back(i);
    }
}

class Solution {
public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
  		int n = nums.size();
        if(k == 1) return 2*accumulate(nums.begin(), nums.end(), 0LL);
        vector<int> nextGreater(n, -1), prevGreater(n, -1), nextSmaller(n, -1), prevSmaller(n, -1);
        compute(nums, nextGreater, [](int a, int b) { return a > b; }, false);
		compute(nums, prevGreater, [](int a, int b) { return a >= b; }, true);
		compute(nums, nextSmaller, [](int a, int b) { return a < b; }, false);
		compute(nums, prevSmaller, [](int a, int b) { return a <= b; }, true);
        long long ans = 0;

        auto ways = [&](int a, int b) -> long long {
            int cntA = (a + 1), cntB = (b + 1);
        	int cntBig = min(cntA, k - b);
        	int cntSmall = cntA - cntBig;

        	return cntBig * cntB + cntSmall * b - cntSmall * (cntSmall - 1) / 2;
        };
        for(int i = 0; i < n; i++) {
        	long long cnt = 0;
            int leftBound = max(0, i - k + 1), rightBound = min(i + k - 1, n-1);

            if(prevSmaller[i] >= 0) leftBound = max(leftBound, prevSmaller[i] + 1); 
            if(nextSmaller[i] >= 0) rightBound = min(rightBound, nextSmaller[i] - 1);
            ans += ways(i - leftBound, rightBound - i) * nums[i];

        	leftBound = max(0, i - k + 1), rightBound = min(i + k - 1, n-1);
	        if(prevGreater[i] >= 0) leftBound = max(leftBound, prevGreater[i] + 1); 
	        if(nextGreater[i] >= 0) rightBound = min(rightBound, nextGreater[i] - 1);
	        ans += ways(i - leftBound, rightBound - i) * nums[i];
        }
        return ans;
    }
};