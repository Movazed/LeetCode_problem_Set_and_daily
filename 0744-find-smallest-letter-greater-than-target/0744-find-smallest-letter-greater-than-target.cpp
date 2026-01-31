class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> charFreq(26,0);
        for(int i=0;i<letters.size();i++){
            int charIndex=letters[i]-'a';
            charFreq[charIndex]++;
        }

        int startIndex = target -'a' + 1;
        for(int i = startIndex; i < 26; i++){
            if(charFreq[i]){
                return char('a' + i);
            }
        }
        return letters[0];
    }
};