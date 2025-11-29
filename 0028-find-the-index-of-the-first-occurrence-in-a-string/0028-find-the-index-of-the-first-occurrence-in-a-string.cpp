class Solution {
public:
    int strStr(string haystack, string needle) {
        string hs = haystack;
        string nd = needle;

        if(hs.length() < needle.length()){
            return -1;
        }

        for(int i = 0; i <= hs.length() - nd.length(); i++){
        if (hs.substr(i, nd.length()) == nd) {
                return i;
            }
        }
        return -1;
    }
};