#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> maxFreq;

        for (const string& word : words2) {
            unordered_map<char, int> tempFreq;
            for (char ch : word) {
                tempFreq[ch]++;
            }
            for (auto& [ch, count] : tempFreq) {
                maxFreq[ch] = max(maxFreq[ch], count);
            }
        }

        vector<string> result;

        for (const string& word : words1) {
            unordered_map<char, int> wordFreq;
            for (char ch : word) {
                wordFreq[ch]++;
            }

            bool isUniversal = true;
            for (auto& [ch, count] : maxFreq) {
                if (wordFreq[ch] < count) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                result.push_back(word);
            }
        }

        return result;
    }
};