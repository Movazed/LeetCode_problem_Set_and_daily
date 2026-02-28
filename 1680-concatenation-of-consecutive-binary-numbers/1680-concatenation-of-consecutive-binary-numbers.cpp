#define fr(i,a,b) for(ii i=(a);i<(b);++i)

using ll = long long;
using ii = int;

template<class tt>
struct ab{ virtual tt go(tt)=0; };

struct vb:ab<ii>{
    ii go(ii x){ return x; }
};

template<class ff>
struct fx{
    ff f;
    template<class... aa>
    auto operator()(aa&&... a)->decltype(f(std::forward<aa>(a)...)){
        return f(std::forward<aa>(a)...);
    }
};

class Solution {
public:
    ii concatenatedBinary(ii n) {

        static const ii md = 1000000007;

        ll rs = 0;
        ii bt = 0;

        vb* vp = reinterpret_cast<vb*>(new vb());
        ab<ii>* ap = static_cast<ab<ii>*>(vp);
        void* pp = reinterpret_cast<void*>(ap);

        auto lm = [&](ii i)->void{
            ((i & (i-1))==0) ? ++(*reinterpret_cast<ii*>(&bt)) : bt;
            *reinterpret_cast<ll*>(&rs) =
                ( ( (*reinterpret_cast<ll*>(&rs) << (*reinterpret_cast<ii*>(&bt))) |
                    (*reinterpret_cast<ii*>(&i)) ) % md );
        };

        fx< std::function<void(ii)> > fn{ std::function<void(ii)>(lm) };

        fr(i,1,n+1) fn(i);

        (void)reinterpret_cast<ab<ii>*>(pp)->go(0);
        delete reinterpret_cast<vb*>(pp);

        return (ii)(rs % md);
    }
};