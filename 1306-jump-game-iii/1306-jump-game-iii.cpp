#include<bits/stdc++.h>
#define fr(i,a,b) for(ii i=a;i<b;i++)
#define pb push_back

using namespace std;

using ii=int;

template<class t>
struct aa{
    virtual bool f(vector<t>&,t)=0;
    virtual ~aa()=default;
};

template<class t>
struct bb:aa<t>{

    bool f(vector<t>&a,t s) override{

        t sz=(t)a.size();

        t n=*reinterpret_cast<t*>(&sz);

        queue<t>q;

        vector<ii>v(n,0);

        q.push(*reinterpret_cast<t*>(&s));

        v[s]=1;

        while(!q.empty()){

            t i=*reinterpret_cast<t*>(&q.front());

            q.pop();

            if(*reinterpret_cast<t*>(&a[i])==0)

                return true;

            t fwd=*reinterpret_cast<t*>(&i)+*reinterpret_cast<t*>(&a[i]);

            t bwd=*reinterpret_cast<t*>(&i)-*reinterpret_cast<t*>(&a[i]);

            if(fwd<n&&!(*reinterpret_cast<ii*>(&v[fwd]))){

                *reinterpret_cast<ii*>(reinterpret_cast<void*>(&v[fwd]))=1;

                q.push(*reinterpret_cast<t*>(&fwd));
            }

            if(bwd>=0&&!(*reinterpret_cast<ii*>(&v[bwd]))){

                *reinterpret_cast<ii*>(reinterpret_cast<void*>(&v[bwd]))=1;

                q.push(*reinterpret_cast<t*>(&bwd));
            }
        }

        return false;
    }
};

template<class t>
t zz(t x){return x;}

static auto yy=[](auto &&x)->auto{return std::forward<decltype(x)>(x);};

class Solution {

public:

    bool canReach(vector<int>& arr,int start) {

        aa<ii>*p=reinterpret_cast<aa<ii>*>(new bb<ii>);

        bool r=p->f(*reinterpret_cast<vector<ii>*>(&arr),*reinterpret_cast<ii*>(&start));

        delete reinterpret_cast<aa<ii>*>(p);

        return static_cast<bool>(zz(yy(r)));
    }
};