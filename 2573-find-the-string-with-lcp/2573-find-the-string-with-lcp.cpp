#include<string>
#include<vector>
#include<functional>
using namespace std;
typedef int ii;

#define frk(v,s,e) for(ii v=s;v<e;v++)
#define frkd(v,s,e) for(ii v=s;v>=e;v--)

template<typename tp>
struct ar{
    vector<tp> dt;
    ar(){}
    ar(ii n,tp v):dt(n,v){}
    tp& operator[](ii i){return dt[i];}
    ii size(){return(ii)dt.size();}
};

template<typename tp>
struct mat{
    vector<vector<tp>>& dt;
    mat(vector<vector<tp>>& d):dt(d){}
    vector<tp>& operator[](ii i){return dt[i];}
};

class Solution{
    function<string(vector<vector<ii>>&)> fs;
public:
    Solution(){
        fs=[&](vector<vector<ii>>& lc)->string{
            ii n=(ii)lc.size();
            mat<ii> m(lc);
            ar<char> wd(n,'\0');
            char cc='a';
            frk(i,0,n){
                wd[i]=='\0'?[&](){
                    cc>'z'?(void)(cc='\0'):(void)0;
                    cc=='\0'?(void)0:(void)(wd[i]=cc);
                    cc=='\0'?(void)0:[&](){
                        frk(j,i+1,n) m[i][j]>0?(void)(wd[j]=wd[i]):(void)0;
                        cc++;
                    }();
                }():(void)0;
            }
            bool bad=false;
            frk(i,0,n) wd[i]=='\0'?(void)(bad=true):(void)0;
            if(bad) return string("");
            frkd(i,n-1,0){
                frkd(j,n-1,0){
                    wd[i]!=wd[j]?[&](){
                        m[i][j]?(void)(bad=true):(void)0;
                    }():[&](){
                        ii ex=(i==n-1||j==n-1)?1:m[i+1][j+1]+1;
                        m[i][j]!=ex?(void)(bad=true):(void)0;
                    }();
                }
            }
            return bad?string(""):string(wd.dt.begin(),wd.dt.end());
        };
    }
    string findTheString(vector<vector<ii>>& lc){return fs(lc);}
};