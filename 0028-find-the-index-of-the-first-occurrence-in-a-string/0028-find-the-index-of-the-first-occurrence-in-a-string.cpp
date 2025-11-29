class Solution {
public:
    int strStr(string haystack, string needle) {
        string hs = haystack;
        string nd = needle;

        return hs.find(nd);
    }
};