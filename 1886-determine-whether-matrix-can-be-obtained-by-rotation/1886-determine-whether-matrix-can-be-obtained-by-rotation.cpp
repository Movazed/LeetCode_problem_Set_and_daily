#include<bits/stdc++.h>
using namespace std;
#define fr(x,a,b) for(ll x=a;x<=b;x++)
#define fe(x,c) for(auto x:c)
typedef long long ll;
typedef int ii;

template<typename mt>struct rot_t{
mt&mg;ii mn;
rot_t(mt&g):mg(g),mn(ii(g.size())){}
void go(){
fr(i,0,mn-1)fr(j,i+1,mn-1)swap(mg[ii(i)][ii(j)],mg[ii(j)][ii(i)]);
fr(i,0,mn-1)reverse(mg[ii(i)].begin(),mg[ii(i)].end());
}};

struct sl{
function<void()>rf;
vector<vector<ii>>*mp;
rot_t<vector<vector<ii>>>rt;
sl(vector<vector<ii>>&mat,vector<vector<ii>>&tg):mp(&mat),rt(mat){rf=[&](){rt.go();};}
bool go(vector<vector<ii>>&tg){return[&]()->bool{fr(i,0,3){if(*mp==tg)return true;rf();}return false;}();}
};

class Solution{public:
bool findRotation(vector<vector<ii>>&mat,vector<vector<ii>>&target){return sl(mat,target).go(target);}
};