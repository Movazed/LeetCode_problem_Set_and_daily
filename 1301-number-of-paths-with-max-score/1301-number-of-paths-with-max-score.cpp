#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int ii;
typedef vector<ii> vii;
#define md 1000000007
#define re return
struct sl{
ii n;
sl(ii n):n(n){}
void upd(ll&wy,vii&sc,vii&wc,ii j,ii bt){
sc[j]==bt?(void)(wy+=wc[j],0):void();
}
vii run(vector<string>&bd){
vii ns(n+1,-1),nw(n+1,0);
for(ii i=n-1;i>=0;i--){
vii cs(n+1,-1),cw(n+1,0);
for(ii j=n-1;j>=0;j--){
char cl=bd[i][j];
if(cl=='X')continue;
if(cl=='S'){cs[j]=0;cw[j]=1;continue;}
ii bt=max({ns[j],cs[j+1],ns[j+1]});
if(bt==-1)continue;
ll wy=0;
upd(wy,ns,nw,j,bt);
upd(wy,cs,cw,j+1,bt);
upd(wy,ns,nw,j+1,bt);
cs[j]=bt+(cl=='E'?0:cl-'0');
cw[j]=wy%md;
}
ns=std::move(cs);nw=std::move(cw);
}
re ns[0]==-1?vii{0,0}:vii{ns[0],nw[0]};
}
};
class Solution{
public:
vector<int>pathsWithMaxScore(vector<string>&board){
re sl(board.size()).run(board);
}
};