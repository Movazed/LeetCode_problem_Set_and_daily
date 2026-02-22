using ll = long long;
using ii = int;

#define wl(c) while(c)

template<class tt>
struct ab{
    virtual tt go(tt)=0;
};

template<class tt>
struct cd:ab<tt>{
    tt go(tt x) override { return x; }
};

template<class tt>
static tt fx(tt x){
    function<tt(tt)> fn = [](tt v)->tt{ return v; };
    return fn(x);
}

class Solution {
public:
    ii binaryGap(ii n) {

        ii mg=0,lp=-1,cp=0;
        ii *pm=&mg,*pl=&lp,*pc=&cp;
        ii nn = n;

        cd<ii> ob;
        ab<ii>* dp = &ob;

        void* pv = reinterpret_cast<void*>(&nn);
        ii* pn = static_cast<ii*>(pv);

        wl(*pn>0){

            ((*pn & 1)
                ? ( *pl!=-1
                        ? (void)(*pm = max(*pm, dp->go(fx(*pc-*pl))))
                        : (void)0,
                    (void)(*pl=*pc)
                  )
                : (void)0
            );

            *pn >>= 1;
            ++(*pc);
        }

        return *pm;
    }
};