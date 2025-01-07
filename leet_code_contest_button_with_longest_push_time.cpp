typedef long long ll;
#define TIME_TAKEN(i) ((i) == 0 ? events[i][1] : events[i][1]-events[i - 1][1])
#define UPDATE_RESULT(time, button) \
    if ((time) > max_time || ((time) == max_time && (button) < result)) { \
        max_time = (time); \
        result = (button); \
    }
#define LOOP(i, n) for (long long i = 0; i < (n); i++)
class Solution {
public:
int buttonWithLongestTime (vector<vector<int>>& events) 
{
        ll n= events.size();
        ll max_time = 0;
        ll result= events[0][0]; 

        LOOP(i , n) {
            ll time_taken = TIME_TAKEN(i);
            UPDATE_RESULT(time_taken, events[i][0]);}
return result;}
};