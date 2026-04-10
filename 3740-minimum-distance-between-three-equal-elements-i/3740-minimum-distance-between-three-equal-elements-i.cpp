#include<vector>
#include<functional>

typedef long long ll;
typedef int ii;

#define fl(v,e) for(ii v=0;v<(ii)(e);v++)
#define mn(a,b) ((a)<(b)?(a):(b))
#define sc(a,b) ((a)==(b))

template<typename vt>
struct pw{
    vt*bg;
    ii ln;
    pw(vt*b,ii l):bg(b),ln(l){}
    vt&operator[](ii i){return *(bg+i);}
};

template<typename rt>
struct pf{
    std::function<rt()>op;
    pf(std::function<rt()>f):op(f){}
    rt operator()(){return op();}
};

template<typename rt,typename at>
struct uf{
    std::function<rt(at)>op;
    uf(std::function<rt(at)>f):op(f){}
    rt operator()(at a){return op(a);}
};

template<typename rt,typename at>
struct bf{
    std::function<rt(at,at)>op;
    bf(std::function<rt(at,at)>f):op(f){}
    rt operator()(at a,at b){return op(a,b);}
};

struct zs{
    bf<ii,ii>pk;
    bf<ii,ii>up;
    uf<ii,ii>od;
    uf<ii,ii>cu;

    zs():
        pk(bf<ii,ii>([](ii p,ii)->ii{return p&255;})),
        up(bf<ii,ii>([](ii p,ii)->ii{return p>>8;})),
        od(uf<ii,ii>([](ii v)->ii{return v&255;})),
        cu(uf<ii,ii>([](ii v)->ii{return v>>8;}))
    {}

    ii minimumDistance(std::vector<ii>&nv){
        ii n=(ii)nv.size();
        ii*lb=new ii[100]();
        pw<ii>pl(lb,100);
        pw<ii>pn(nv.data(),n);
        ii*rp=new ii(200);

        uf<void,ii>step([&](ii i)->void{
            ii vl=*(pn.bg+i)-1;
            ii ps=i+1;
            ii pk2=*(pl.bg+vl);
            ii ov=od(pk2);
            ii cv=cu(pk2);
            *(pl.bg+vl)=cv|(ps<<8);
            (ov)?std::function<void()>([&]()->void{
                *rp=mn(*rp,(ps-ov)<<1);
            })():std::function<void()>([&]()->void{})();
        });

        pf<void>lp([&]()->void{
            fl(i,n)step(i);
        });
        lp();

        ii rs=-(sc(*rp,200))|*rp;
        delete[]lb;
        delete rp;
        return rs;
    }
};

class Solution{
public:
    ii minimumDistance(std::vector<ii>&nv){
        zs*zp=new zs();
        ii rs=zp->minimumDistance(nv);
        delete zp;
        return rs;
    }
};