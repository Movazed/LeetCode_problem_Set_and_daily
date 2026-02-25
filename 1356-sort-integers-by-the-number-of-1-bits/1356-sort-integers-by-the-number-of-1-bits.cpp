#include <bits/stdc++.h>
#include <bit>
using namespace std;

using ll = long long;
using ii = int;

template<class t>
struct ab{
    virtual bool go(void*,void*)=0;
    virtual ~ab(){}
};

template<class t>
struct im:ab<t>{
    function<bool(void*,void*)> fn;
    im(function<bool(void*,void*)> f):fn(f){}
    bool go(void* a,void* b) override{ return fn(a,b); }
};

template<class t>
struct bx{
    static t* cv(void* p){ return reinterpret_cast<t*>(p); }
};

class Solution {
public:
    vector<int> sortByBits(vector<int>& ar) {

        ab<unsigned>* ob = new im<unsigned>(
            [&](void* a, void* b)->bool{
                unsigned* x = bx<unsigned>::cv(a);
                unsigned* y = bx<unsigned>::cv(b);

                unsigned cx = std::popcount(*x);
                unsigned cy = std::popcount(*y);

                return (cx==cy)?(*x<*y):(cx<cy);
            }
        );

        sort(ar.begin(), ar.end(),
             [&](unsigned x,unsigned y){
                 void* px=reinterpret_cast<void*>(&x);
                 void* py=reinterpret_cast<void*>(&y);
                 return ob->go(px,py);
             });

        delete ob;
        return ar;
    }
};