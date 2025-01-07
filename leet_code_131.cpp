class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> par;
        vector<vector<string>> pars;
        partition(s, 0, par, pars);
        return pars;
    }

private:
    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l++] != s[r--]){
                return false;
            }
        }
        return true;
    }
    void partition(string& s, int start, vector<string>& par, vector<vector<string>>& pars){
        int n = s.length();
        if(n == start){
            pars.push_back(par);
        } else {
            for(int i = start; i < n; i++){
                if(isPalindrome(s, start, i)){
                    par.push_back(s.substr(start, i - start + 1));
                    partition(s, i + 1, par, pars);
                    par.pop_back();
                }

            }
        }
    }
};