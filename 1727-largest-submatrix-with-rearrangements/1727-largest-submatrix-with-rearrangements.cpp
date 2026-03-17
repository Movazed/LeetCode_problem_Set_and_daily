#include <bits/stdc++.h>
using namespace std;

using ii = int;
using ll = long long;

#define fr(i,a,b) for(ii i=(a);i<(b);++i)
#define rf(i,a,b) for(ii i=(a);i>=(b);--i)

template<class t> struct ab{ virtual t g(t)=0; virtual ~ab(){} };
template<class t> struct im:ab<t>{ t g(t v){ return v; } };

class solution{
public:
    static ii f(vector<vector<ii>>& m){
        ii r=m.size(),c=m[0].size();
        ii a=0;
        ii* p=m[0].data();
        fr(i,0,c) a+=(*(p+i)==1);

        if(r==1) return a;

        if(c==1){
            fr(i,1,r)
                *(m[i].data())+=(*(m[i].data()))*(*(m[i-1].data())),
                a=max(a,*(m[i].data()));
            return a;
        }

        fr(i,1,r){
            fr(j,0,c)
                *(m[i].data()+j)+=*(m[i].data()+j)*(*(m[i-1].data()+j));

            auto &rw=m[i];
            ii mn=i+1,mx=0;

            for(auto x:rw) mn=min(mn,x),mx=max(mx,x);

            vector<ii> f(mx-mn+1,0);
            for(auto x:rw) (*(f.data()+(x-mn)))++;

            ii ac=0;
            for(ii x=mx-mn;ac<c;x--){
                (*(f.data()+x)>0)?
                    (ac+=*(f.data()+x),a=max(a,ac*(x+mn)))
                    :0;
            }
        }
        return a;
    }
};

auto init=[](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution{
public:
    int largestSubmatrix(vector<vector<int>>& m){
        struct aa{ virtual ii h(vector<vector<ii>>&)=0; };
        struct bb:aa{
            ii h(vector<vector<ii>>& x){
                return ((ii(*)(vector<vector<ii>>&))(&solution::f))(x);
            }
        };
        aa* o=new bb();
        return o->h(reinterpret_cast<vector<vector<ii>>&>(m));
    }
};