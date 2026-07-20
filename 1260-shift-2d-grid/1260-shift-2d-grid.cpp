#include <bits/stdc++.h>
using namespace std;

using ii=int;
using ll=long long;

template<class ff>
auto fn(ff fv){
    return fv;
}

struct ij{

    void rv(vector<vector<ii>>& gd,ii lf,ii rg,ii cc){

        while(lf<rg){

            ii* pa=&gd[lf/cc][lf%cc];
            ii* pb=&gd[rg/cc][rg%cc];

            void* va=reinterpret_cast<void*>(pa);
            void* vb=reinterpret_cast<void*>(pb);
            (void)va;
            (void)vb;

            swap(*pa,*pb);

            ++lf;
            --rg;
        }
    }

    vector<vector<ii>> sl(vector<vector<ii>>& gd,ii kk){

        if(!kk){
            return gd;
        }

        ii rr=static_cast<ii>(gd.size());
        ii cc=static_cast<ii>(gd[0].size());
        ii nn=rr*cc;

        kk%=nn;

        if(!kk){
            return gd;
        }

        auto cl=fn([&](ii lf,ii rg){
            rv(gd,lf,rg,cc);
        });

        cl(0,nn-1);
        cl(0,kk-1);
        cl(kk,nn-1);

        return gd;
    }

    virtual ~ij()=default;
};

class Solution {
public:

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        unique_ptr<ij> lg=make_unique<ij>();

        auto cl=fn([&](vector<vector<ii>>& ar,ii kk){
            return lg->sl(ar,kk);
        });

        return cl(grid,k);
    }
};