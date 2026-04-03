#include<vector>
#include<unordered_map>
#include<algorithm>
#include<functional>

typedef long long ll;
typedef int ii;

#define fl(v,e) for(ii v=0;v<(ii)(e);v++)
#define fl1(v,s,e) for(ii v=(s);v<=(ii)(e);v++)
#define mn(a,b) ((a)<(b)?(a):(b))
#define mx(a,b) ((a)>(b)?(a):(b))
#define ub(b,e,v) (ii)(std::upper_bound(b,e,v)-(b))
#define lb(b,e,v) (ii)(std::lower_bound(b,e,v)-(b))
#define dr(p,i) (*(p.bg+i))

template<typename vt>
struct pw{
    vt*bg;
    ii ln;
    pw(vt*b,ii l):bg(b),ln(l){}
    vt&operator[](ii i){return *(bg+i);}
};

template<typename rt,typename a1,typename a2>
struct bf{
    std::function<rt(a1,a2)>op;
    bf(std::function<rt(a1,a2)>f):op(f){}
    rt operator()(a1 a,a2 b){return op(a,b);}
};

template<typename rt>
struct pf{
    std::function<rt()>op;
    pf(std::function<rt()>f):op(f){}
    rt operator()(){return op();}
};

struct zs{
    bf<ii,ii,ii>cmb;
    bf<ii,ii,ii>cmr;

    zs():
        cmb(bf<ii,ii,ii>([](ii sl,ii sr)->ii{return mx(sl,sr);})),
        cmr(bf<ii,ii,ii>([](ii sl,ii sr)->ii{return mx(sl,sr);}))
    {}

    ii maxWalls(std::vector<ii>&rb,std::vector<ii>&ds,std::vector<ii>&wl){
        ii n=(ii)rb.size();
        std::unordered_map<ii,ii>*mp=new std::unordered_map<ii,ii>();
        fl(i,n)(*mp)[*(rb.data()+i)]=*(ds.data()+i);
        ii wn=(ii)wl.size();
        std::sort(rb.data(),rb.data()+n);
        std::sort(wl.data(),wl.data()+wn);
        std::vector<ii>*lv=new std::vector<ii>(n,0);
        std::vector<ii>*rv=new std::vector<ii>(n,0);
        std::vector<ii>*nv=new std::vector<ii>(n,0);
        pw<ii>pr(rb.data(),n);
        pw<ii>pw2(wl.data(),wn);
        pw<ii>pl(lv->data(),n);
        pw<ii>prv(rv->data(),n);
        pw<ii>pn(nv->data(),n);
        ii*wb=wl.data();ii*we=wl.data()+wn;

        bf<ii,ii,ii>lbnd([&](ii lo,ii)->ii{return lb(wb,we,lo);});
        bf<ii,ii,ii>ubnd([&](ii hi,ii)->ii{return ub(wb,we,hi);});

        pf<void>fill([&]()->void{
            fl(i,n){
                ii ri=dr(pr,i);
                ii di=(*mp)[ri];
                ii p1=ub(wb,we,ri);
                ii lp=(i>=1)
                    ?lb(wb,we,mx(ri-di,dr(pr,i-1)+1))
                    :lb(wb,we,ri-di);
                dr(pl,i)=p1-lp;
                ii rp=(i<n-1)
                    ?ub(wb,we,mn(ri+di,dr(pr,i+1)-1))
                    :ub(wb,we,ri+di);
                ii p2=lb(wb,we,ri);
                dr(prv,i)=rp-p2;
                (i==0)?void():[&]()->void{
                    ii p3=lb(wb,we,dr(pr,i-1));
                    dr(pn,i)=p1-p3;
                }();
            }
        });
        fill();

        ll*sl=new ll(dr(pl,0));
        ll*sr=new ll(dr(prv,0));
        pf<void>dp([&]()->void{
            fl1(i,1,n-1){
                ll cl=(ll)mx(
                    (ii)(*sl)+dr(pl,i),
                    (ii)(*sr)-dr(prv,i-1)+mn(dr(pl,i)+dr(prv,i-1),dr(pn,i))
                );
                ll cr=(ll)mx((ii)(*sl)+dr(prv,i),(ii)(*sr)+dr(prv,i));
                *sl=cl;*sr=cr;
            }
        });
        dp();
        ii rs=(ii)mx((ll)*sl,(ll)*sr);
        delete mp;delete lv;delete rv;delete nv;delete sl;delete sr;
        return rs;
    }
};

class Solution{
public:
    ii maxWalls(std::vector<ii>&rb,std::vector<ii>&ds,std::vector<ii>&wl){
        return zs().maxWalls(rb,ds,wl);
    }
};