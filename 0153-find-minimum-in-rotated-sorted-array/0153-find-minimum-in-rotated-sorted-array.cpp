#include<bits/stdc++.h>
#define ii int
#define ll long long
#define vc vector
#define pb push_back
#define fr(i,a,b) for(ii i=(a);i<(b);++i)
#define wl(x) while(x)
#define re return

using namespace std;

template<class t>
using cp=t*;

struct ax{
    virtual ii fx(vc<ii>&)=0;
};

struct bx:ax{

    ii fx(vc<ii>& nm) override{

        cp<vc<ii>> p=&nm;

        auto fn=[&](ii x)->bool{

            cp<ii> bk=&((*(p)).back());

            re x>(*bk);
        };

        auto it=partition_point(
            (*(p)).begin(),
            (*(p)).end(),
            [&](ii x)->bool{

                cp<ii> px=&x;

                re fn((*reinterpret_cast<ii*>(px)));
            }
        );

        cp<ii> rt=&(*it);

        re (*rt);
    }
};

class Solution {
public:

    int findMin(vector<int>& nums) {

        vc<ii> nm;

        for(auto &x:nums)
            nm.pb((*reinterpret_cast<ii*>(&x)));

        ax* ob=new bx();

        ii an=((ob!=nullptr)?ob->fx(nm):0);

        delete ob;

        re static_cast<int>(an);
    }
};