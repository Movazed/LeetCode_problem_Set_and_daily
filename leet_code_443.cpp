#define ll long long
#define cc const char
class Solution {
public:
    int compress(vector<char>& chars) {
        ll ans = 0;

        for(ll i = 0; i < chars.size();){
            cc letter = chars[i];
            ll count = 0;


            while(i < chars.size() && letter == chars[i]){
                ++count;
                ++i;
            }

            chars[ans++] = letter;

            if(count > 1){
                for(cc c : to_string(count)){
                    chars[ans++] = c;
                }
            }

        }
        return ans;
    }
};