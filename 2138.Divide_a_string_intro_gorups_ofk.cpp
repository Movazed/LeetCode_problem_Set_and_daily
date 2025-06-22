class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;

        while(s.size() % k){
            s += fill;
        }

        string curr = "";

        for(int i = 0; i < s.size(); i++){
            curr += s[i];

            if(curr.size() == k){
                ans.push_back(cur);
                cur = "";
            }
        }
        return ans;
    }
};