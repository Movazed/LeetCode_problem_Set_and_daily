#include<string>
#include<array>
#include<algorithm>
#include<functional>

typedef long long ll;
typedef int ii;

#define lp(v,e) for(ii v=0;v<(ii)(e);v++)
#define ev(i) ((i)&1)
#define ap(b,c) b[ev(i)]+=c
#define ss(s) std::sort((s).begin(),(s).end())

template<ii n,typename vt>
struct bk{
    std::array<vt,n>dt;
    std::function<vt&(ii)>ac;
    bk():ac([&](ii i)->vt&{return dt[i];}){dt.fill(vt{});}
    vt&operator[](ii i){return ac(i);}
    bool operator==(bk<n,vt>&o){return dt==o.dt;}
};

template<typename ct>
struct pw{
    ct*bg;
    ii ln;
    pw(ct*b,ii l):bg(b),ln(l){}
    ct operator[](ii i){return *(bg+i);}
};

template<typename vt,ii n>
struct sr{
    std::function<void(bk<n,vt>&)>op;
    sr(std::function<void(bk<n,vt>&)>f):op(f){}
    void operator()(bk<n,vt>&b){op(b);}
};

class Solution{
public:
    bool checkStrings(std::string s1,std::string s2){
        bk<2,std::string>*pa=new bk<2,std::string>();
        bk<2,std::string>*pb=new bk<2,std::string>();
        pw<const char>w1(s1.data(),(ii)s1.size());
        pw<const char>w2(s2.data(),(ii)s2.size());
        lp(i,w1.ln){
            (*pa)[ev(i)]+=w1[i];
            (*pb)[ev(i)]+=w2[i];
        }
        sr<std::string,2>sop([](bk<2,std::string>&bk)->void{
            lp(j,2)ss(bk[j]);
        });
        sop(*pa);sop(*pb);
        bool rs=(*pa==*pb);
        delete pa;delete pb;
        return rs;
    }
};