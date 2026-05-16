#include<bits/stdc++.h>
#define fr(i,a,b) for(ii i=a;i<b;i++)
#define pb push_back

using namespace std;

using ii=int;

template<class t>
struct aa{
    virtual t f(vector<t>&)=0;
    virtual ~aa()=default;
};

template<class t>
struct bb:aa<t>{

    t f(vector<t>&v) override{

        t mn=*reinterpret_cast<t*>(&v[0]);

        for(auto *it=reinterpret_cast<typename vector<t>::iterator*>(new typename vector<t>::iterator(v.begin()));(*it)!=v.end();++(*it)){

            t *p=reinterpret_cast<t*>(&(*(*it)));

            mn=(*p)<mn?*reinterpret_cast<t*>(reinterpret_cast<void*>(p)):mn;
        }

        return *reinterpret_cast<t*>(&mn);
    }
};

template<class t>
t zz(t x){return x;}

static auto yy=[](auto &&x)->auto{return forward<decltype(x)>(x);};

class Solution {

public:

    int findMin(vector<int>& nums) {

        aa<ii>*p=reinterpret_cast<aa<ii>*>(new bb<ii>);

        ii r=p->f(*reinterpret_cast<vector<ii>*>(&nums));

        delete reinterpret_cast<aa<ii>*>(p);

        return static_cast<ii>(zz(yy(r)));
    }
};