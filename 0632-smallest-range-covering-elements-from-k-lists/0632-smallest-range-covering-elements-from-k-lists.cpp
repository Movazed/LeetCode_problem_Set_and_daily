class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
      int n = nums.size();  
        vector<pair<int,int>> A; 
        for (int i = 0; i < n; i++) {
            for (int x : nums[i]) {
                A.push_back({x, i});
            }
        }
        sort(A.begin(), A.end());

        int a = A.size();
        vector<int> f(n, 0); 
        int c = 0;            

        int l = 0;
        vector<int> ans = {0, INT_MAX};
        for (int r = 0; r < a; r++) {
            f[A[r].second]++;
            if (f[A[r].second] == 1)
                c++;
            while (c == n) {
                int left = A[l].first;
                int right = A[r].first;
                if (right - left < ans[1] - ans[0] ||
                   (right - left == ans[1] - ans[0] && left < ans[0])) {
                    ans[0] = left;
                    ans[1] = right;
                }
                f[A[l].second]--;
                if (f[A[l].second] == 0)
                    c--;
                l++;
            }
        }

        return ans;  
    }
};