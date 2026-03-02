#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = int;

#define fr(i,a,b) for(ii i=(a);i<(b);++i)
#define fd(i,a,b) for(ii i=(a);i>=(b);--i)
#define wh(x) while(x)

template<class t>
struct ab{ virtual t go(t a,t b)=0; };

struct ad:ab<ii>{
    ii go(ii a,ii b) override{ return a+b; }
};

template<class f>
auto mk(f x){ return x; }

class Solution {
public:
    ii minSwaps(vector<vector<int>>& grid)
    {
        ii n=(ii)grid.size();

        ii *pn=static_cast<ii*>(reinterpret_cast<void*>(&n));

        vector<ii> zr(*pn);
        vector<ii> *pz=static_cast<vector<ii>*>(reinterpret_cast<void*>(&zr));

        vector<vector<int>> *pg=static_cast<vector<vector<int>>*>(reinterpret_cast<void*>(&grid));

        fr(i,0,*pn)
        {
            ii ct=0;
            ii *pc=static_cast<ii*>(reinterpret_cast<void*>(&ct));

            fd(j,(*pn)-1,0)
                (((*pg)[i][j]==0)?
                    (void)(++(*pc)):
                    (void)(j=-1));

            (*pz)[i]=*pc;
        }

        ii sw=0;
        ii *psw=static_cast<ii*>(reinterpret_cast<void*>(&sw));

        ad *pd=static_cast<ad*>(reinterpret_cast<void*>(new ad()));

        auto lm=mk([&](ii a,ii b){
            return pd->go(a,b);
        });

        fr(i,0,*pn)
        {
            ii nd=(*pn)-i-1;
            ii *pnd=static_cast<ii*>(reinterpret_cast<void*>(&nd));

            ii j=i;
            ii *pj=static_cast<ii*>(reinterpret_cast<void*>(&j));

            wh((*pj)<(*pn) && (*pz)[*pj]<(*pnd)) ++(*pj);

            ((*pj)==(*pn)) ? (void)(ii(-1)) : (void)0;

            if((*pj)==(*pn)){ delete pd; return -1; }

            wh((*pj)>i)
            {
                swap((*pz)[*pj],(*pz)[(*pj)-1]);
                --(*pj);
                *psw=lm(*psw,1);
            }
        }

        delete pd;
        return *psw;
    }
};