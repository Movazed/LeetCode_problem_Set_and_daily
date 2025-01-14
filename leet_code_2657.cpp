#define ll long long

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        ll n = A.size();
        vector<int> ans;
        vector<int> freq(n + 1, 0);
        ll common = 0;
        for(ll i = 0; i < n; i++){
            if(++freq[A[i]] == 2){
                common++;
            }

            if(++freq[B[i]] == 2){
                common++;
            }
            ans.push_back(common);
        }
        return ans;
    }
};