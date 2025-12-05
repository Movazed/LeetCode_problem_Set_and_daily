class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int repo = accumulate(nums.begin(), nums.end(), 0);  
        int count = 0;
        int se = 0; 

        for (int i = 0; i < n - 1; i++) {

            se += nums[i];  
            int lo = repo - se;  

            if ((se - lo) % 2 == 0) {
                count++;
            }
        }

        return count;
    }
};

// class Solution {
// public:
//     int countPartitions(vector<int>& nums) {
//         int n = nums.size();
//         int repo;
//         int count;
//         for(int i = 0; i <= n; i++){
//             int se = nums[i];

//             for(int j = i + 1; j <= n; j++){
//                 repo = accumulate(nums.begin(), nums.end(),0);
//             }
//         int lo = repo - se;

//         if(lo % 2 == 0)
//         {
//             count =count + 1;
            
//         }   
//         }

//         return count;


//     }
// };
