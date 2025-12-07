class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; //for negs

        string s = to_string(x);
        string r = s;
        reverse(r.begin(), r.end());

        return s == r;
    }
};