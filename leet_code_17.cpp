class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()){
            return res;
        }

        unordered_map<char, string> digitsToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}            
        };

        backtrack(digits, 0, "", res, digitsToLetters);
        return res;
    }

    void backtrack(const string& digits, int idx, string comb, vector<string>& res, unordered_map<char, string>& digitsToLetters){
        if(idx == digits.length()){
            res.push_back(comb);
            return;
        }

        string letters = digitsToLetters.at(digits[idx]);

        for(char letter: letters){
            backtrack(digits, idx + 1, comb + letter, res, digitsToLetters);
        }
    }
};