class Solution {
public:
    // it actually doesn't beats 100% sorry guys might be misleading its a creative one tho .....
    bool isPalindrome(string s) {
        for(char &c : s){
            c = tolower(static_cast<unsigned char>(c));
        }
        for (int i = 0; i < s.length(); ) {
            if (!isalnum(static_cast<unsigned char>(s[i]))) {
                s.erase(i, 1);  
            } else {
                i++;
            }
        }
        string re = s;

         reverse(re.begin(), re.end());

        if(s == re){
            return true;
        } else {
            return false;
        }
    }
};