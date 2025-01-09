class Solution {
public:
    int maxVowels(string s, int k) {
        int count  = 0, maxcount = 0;

        for(int i = 0; i < k; i++){
            if(isVowel(s[i])){
                count++;
            }
        }
        maxcount = count;

        for(int i = k; i < s.length(); i++){
            if(isVowel(s[i])){
                count++;
            }
            if(isVowel(s[i - k])){
                count--;
            }
            maxcount = max(count, maxcount);
        }
        return maxcount;
    }

    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};