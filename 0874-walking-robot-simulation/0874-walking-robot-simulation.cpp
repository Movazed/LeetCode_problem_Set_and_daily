#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = int;

#define lp(i,a,b) for(ii i=(a);i<(b);++i)

struct bv {
    virtual void* x(void*,void*) = 0;
    virtual ~bv() {}
};

template<class t>
struct bw : bv {
    void* x(void* a, void* b) override {
        return (void*)(*(t*)a)(b);
    }
};

class Solution {
    template<typename a>
    a z(a q){return q;}

    static pair<ii,ii> r(void* p){
        auto *k = (pair<ii,ii>*)p;
        return *k;
    }

public:
    ii robotSim(vector<ii>& c, vector<vector<ii>>& o) {
        set<pair<ii,ii>> s;
        for(auto &u:o){
            auto *w=(void*)&u;
            auto &q=*(vector<ii>*)w;
            s.insert({q[0],q[1]});
        }

        vector<pair<ii,ii>> d={{0,1},{1,0},{0,-1},{-1,0}};
        ii x=0,y=0;
        ii dr=0;
        ii mx=0;

        auto mv=[&](void* v)->ll{
            auto t=(ii*)(v);
            lp(i,0,*t){
                ii nx=x+d[dr].first;
                ii ny=y+d[dr].second;
                s.count({nx,ny}) ? 0 : (x=nx,y=ny,mx=max(mx,x*x+y*y));
            }
            return 0;
        };

        bw<decltype(mv)> fx;

        for(auto &k:c){
            k==-1 ? (void)(dr=(dr+1)%4) :
            k==-2 ? (void)(dr=(dr+3)%4) :
            (void)fx.x((void*)&mv,(void*)&k);
        }

        return mx;
    }
};