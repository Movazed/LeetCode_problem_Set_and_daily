#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
		for(int i=0;i<hand.size();i++)
		{
			mp[hand[i]]++;
		}

		for(auto it=mp.begin();it!=mp.end();)
		{
			if(it->second>0)
			{
				for(int i=0;i<groupSize;i++)
				{
					if(mp[it->first+i]>0)
					{
						mp[it->first+i]--;
					}
					else
						return false;
				}
			}
			else
				it++;
		}
		return true;
    }
};

int main() {
    Solution solution;
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize = 3;
    cout << (solution.isNStraightHand(hand, groupSize) ? "true" : "false") << endl;
    return 0;
}
