class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;
        static int freq[100001] = {0};

        for(int i = 0; i < static_cast<int>(nums.size()); i++){
            int* ni = reinterpret_cast<int*>(&nums[i]);
            int* pmn = reinterpret_cast<int*>(&mn);
            int* pmx = reinterpret_cast<int*>(&mx);

            if(*ni < *pmn) *pmn = *ni;
            if(*ni > *pmx) *pmx = *ni;

            int* pf = reinterpret_cast<int*>(&freq[*ni]);
            (*pf)++;
        }

        int max_sum = 0;
        int l = mn, r = mx;

        while(l <= r){
            int* pl = reinterpret_cast<int*>(&freq[l]);
            int* pr = reinterpret_cast<int*>(&freq[r]);

            if(*pl == 0){ l++; continue; }
            if(*pr == 0){ r--; continue; }

            max_sum = fmax(max_sum, l + r);
            (*pl)--;
            (*pr)--;
        }

        return max_sum;
    }
};