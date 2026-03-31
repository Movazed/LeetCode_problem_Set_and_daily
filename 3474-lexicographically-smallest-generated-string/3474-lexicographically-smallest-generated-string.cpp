#include<string>
#include<functional>
#include<vector>

typedef long long ll;
typedef int ii;

#define fl(v,e) for(ii v=0;v<(ii)(e);v++)
#define flr(v,s,e) for(ii v=s;v>=(ii)(e);v--)
#define fl1(v,s,e) for(ii v=s;v<=(ii)(e);v++)
#define sc(a,b) ((a)==(b))
#define nsc(a,b) ((a)!=(b))
#define qt(c) ((c)=='?')
#define rv(s,i,j) std::string((s).begin()+(i),(s).begin()+(j))

template<typename ct>
struct pw{
    ct*bg;
    ii ln;
    pw(ct*b,ii l):bg(b),ln(l){}
    ct&operator[](ii i){return *(bg+i);}
};

template<typename vt>
struct op{
    std::function<void(vt&)>fn;
    op(std::function<void(vt&)>f):fn(f){}
    void operator()(vt&v){fn(v);}
};

template<typename vt>
struct qr{
    std::function<bool(vt&,ii)>fn;
    qr(std::function<bool(vt&,ii)>f):fn(f){}
    bool operator()(vt&v,ii i){return fn(v,i);}
};

struct zs{
    std::string generateString(std::string s,std::string t){
        ii n=(ii)s.size(),m=(ii)t.size();
        std::string*an=new std::string(n+m-1,'?');
        std::string*oa=nullptr;
        pw<char>ps(s.data(),n);
        pw<char>pt(t.data(),m);
        pw<char>pa(an->data(),(ii)an->size());

        op<std::string>top([&](std::string&a)->void{
            pw<char>wp(a.data(),(ii)a.size());
            fl(i,n){
                std::function<void()>br=sc(*(ps.bg+i),'T')
                    ?std::function<void()>([&](){
                        fl(j,m){
                            char*cp=wp.bg+i+j;
                            char*tp=pt.bg+j;
                            (nsc(*cp,'?')&&nsc(*cp,*tp))
                                ?(a=std::string(""),void())
                                :(*cp=*tp,void());
                        }
                    })
                    :std::function<void()>([&](){});
                br();
            }
        });

        top(*an);
        if(an->empty()){delete an;return "";}

        oa=new std::string(*an);
        pw<char>po(oa->data(),(ii)oa->size());
        pw<char>pa2(an->data(),(ii)an->size());
        fl(i,(ii)an->size()){
            char*cp=pa2.bg+i;
            *cp=(qt(*cp)?'a':*cp);
        }

        qr<std::string>fop([&](std::string&a,ii i)->bool{
            pw<char>wp(a.data(),(ii)a.size());
            return (nsc(*(ps.bg+i),'F')||(
                nsc(rv(a,i,i+m),t)?(true):(
                    [&]()->bool{
                        bool ok=false;
                        flr(j,i+m-1,i){
                            char*op=po.bg+j;
                            char*ap=wp.bg+j;
                            if(qt(*op)){
                                *ap='b';
                                ok=true;
                                break;
                            }
                        }
                        return ok?true:(a=std::string(""),false);
                    }()
                )
            ));
        });

        fl(i,n){
            if(!fop(*an,i)){delete an;delete oa;return "";}
        }

        std::string rs=*an;
        delete an;delete oa;
        return rs;
    }
};

class Solution{
public:
    std::string generateString(std::string s,std::string t){
        return zs().generateString(s,t);
    }
};