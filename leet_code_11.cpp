#include <vector>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        ll left = 0 ;
        ll right = height.size() - 1;
        ll maxArea = 0;

        while(left < right){

            ll currentArea = min(height[left], height[right]) * (right - left);

            maxArea = max(maxArea, currentArea);


            if(height[left] < height[right]){
                left++;
            } else {
                right--;
            }
        }
        return (int)maxArea;
    }
};