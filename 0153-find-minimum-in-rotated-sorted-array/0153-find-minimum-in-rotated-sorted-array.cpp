1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int left = 0;
5        int right = nums.size() - 1;
6
7        while(left < right){
8            int mid = left + (right - left) / 2;
9
10            if(nums[mid] <= nums[right]){
11                right = mid;
12            } else {
13                left = mid + 1;
14            }
15        }
16        return nums[left];
17    }
18};