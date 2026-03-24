#include<bits/stdc++.h>
#pragma gcc optimize("o3")
#define ll long long
#define ii int
#define md 12345
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define frr(x,a,b) for(ll x=a;x>=b;x--)
using namespace std;
template<typename tp,typename uq>
struct nd{
    tp vl;uq nx;
    nd():vl(0),nx(0){}
    nd(tp a,uq b):vl(a),nx(b){}
    operator tp()const{return vl;}
};
template<typename tp>
using fn=function<tp>;
struct gw{
    ll *rw;
    ll **op;
    ll nr,nc;
    gw(ll r,ll c):nr(r),nc(c),rw(new ll[r*c]),op(new ll*[r]){
        fr(i,0,r) op[i]=rw+i*c;
    }
    ~gw(){delete[]rw;delete[]op;}
    ll* operator[](ll i){return op[i];}
};
struct sl{
    fn<vector<vector<ii>>(vector<vector<ii>>&)> go=[&](vector<vector<ii>>&gd)->vector<vector<ii>>{
        ll n=gd.size(),m=gd[0].size();
        gw *pw=new gw(n,m);
        ll pf=1;
        fr(i,0,n) fr(j,0,m)
            *(pw->op[i]+j)=pf,
            pf=(pf*(*(gd[i].data()+j)%md))%md;
        ll sf=1;
        frr(i,n-1,0) frr(j,m-1,0)
            *(pw->op[i]+j)=(*(pw->op[i]+j)*sf)%md,
            sf=(sf*(*(gd[i].data()+j)%md))%md;
        vector<vector<ii>> rs(n,vector<ii>(m));
        fr(i,0,n) fr(j,0,m) *(rs[i].data()+j)=*(pw->op[i]+j);
        delete pw;
        return rs;
    };
}*sv=new sl();
struct so{
    fn<vector<vector<ii>>(vector<vector<ii>>&)> run=[&](vector<vector<ii>>&gd)->vector<vector<ii>>{
        return sv->go(gd);
    };
};
class Solution{
    so *ob;
public:
    Solution():ob(new so()){}
    ~Solution(){delete ob;}
    vector<vector<ii>> constructProductMatrix(vector<vector<ii>>&gd){
        return ob->run(gd);
    }
};