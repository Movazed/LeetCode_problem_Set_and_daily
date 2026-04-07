class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;
        
        // Try all possible starting positions
        for (int i = 0; i < n; i++) {
            int freq[26] = {0};
            int maxFreq = 0;
            int distinctChars = 0;
            
            // Expand window from position i
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                
                // Update distinct characters count
                if (freq[idx] == 0) {
                    distinctChars++;
                }
                freq[idx]++;
                maxFreq = max(maxFreq, freq[idx]);
                
                // Check if current substring is balanced
                // A substring is balanced if:
                // 1. All characters have same frequency: maxFreq * distinctChars == length
                // 2. OR only one character type exists: distinctChars == 1
                int len = j - i + 1;
                if (maxFreq * distinctChars == len || distinctChars == 1) {
                    maxLen = max(maxLen, len);
                }
            }
        }
        
        return maxLen;
    }
};