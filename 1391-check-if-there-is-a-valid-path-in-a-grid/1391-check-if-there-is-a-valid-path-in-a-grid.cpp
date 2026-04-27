#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(ii i=(a);i<(b);++i)

using ii=int;
using ll=long long;
#define vvi vector<vector<int>>

template<class t>
t& cv(void* p){ return *reinterpret_cast<t*>(p); }

template<class t>
t* cp(void* p){ return reinterpret_cast<t*>(p); }

template<class t>
struct bx{
    virtual t& gt()=0;
    virtual ~bx(){}
};

template<class t>
struct dx:bx<t>{
    t v;
    dx(t x):v(x){}
    t& gt() override{ return v; }
};

class Solution {

    static constexpr ii tr[6][4]={
        {-1,1,-1,3},
        {0,-1,2,-1},
        {3,2,-1,-1},
        {1,-1,-1,2},
        {-1,0,3,-1},
        {-1,-1,1,0}
    };

    static constexpr ii ds[4][2]={
        {-1,0},{0,1},{1,0},{0,-1}
    };

    static constexpr ii st[6][2]={
        {1,3},{0,2},{2,3},
        {1,2},{0,3},{0,1}
    };

public:

    bool hasValidPath(vvi& grid) {

        ii m=(ii)grid.size();
        ii n=(ii)grid[0].size();

        m==1&&n==1 ? true : 0;

        if(m==1&&n==1) return true;

        auto ck=[&](ii di)->bool{

            di==-1 ? true:0;
            if(di==-1) return false;

            ii r=*reinterpret_cast<const ii*>(&ds[di][0]);
            ii c=*reinterpret_cast<const ii*>(&ds[di][1]);

            void* pv=new bitset<90000>;
            auto& vs=cv<bitset<90000>>(pv);

            while(r>=0&&r<m&&c>=0&&c<n){

                ii cl=r*n+c;

                if(vs[cl]){
                    delete cp<bitset<90000>>(pv);
                    return false;
                }

                vs.set(cl);

                di=*reinterpret_cast<const ii*>
                   (&tr[grid[r][c]-1][di]);

                if(di==-1){
                    delete cp<bitset<90000>>(pv);
                    return false;
                }

                if(r==m-1&&c==n-1){
                    delete cp<bitset<90000>>(pv);
                    return true;
                }

                r+=*reinterpret_cast<const ii*>(&ds[di][0]);
                c+=*reinterpret_cast<const ii*>(&ds[di][1]);
            }

            delete cp<bitset<90000>>(pv);
            return false;
        };

        const ii* s=reinterpret_cast<const ii*>
                    (&st[grid[0][0]-1]);

        return ck(*reinterpret_cast<const ii*>(&s[0]))||
               ck(*reinterpret_cast<const ii*>(&s[1]));
    }
};

constexpr ii Solution::tr[6][4];
constexpr ii Solution::ds[4][2];
constexpr ii Solution::st[6][2];