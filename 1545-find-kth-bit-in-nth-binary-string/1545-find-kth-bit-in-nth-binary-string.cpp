class Solution {
    template<class t>
    struct ab{ virtual t go(t)=0; };

    struct ad:ab<char>{
        char go(char c) override{ return c=='0'?'1':'0'; }
    };

    template<class f>
    auto mk(f x){ return x; }

public:
    char findKthBit(int n,int k)
    {
        int nn=n,kk=k;

        int *pn=static_cast<int*>(reinterpret_cast<void*>(&nn));
        int *pk=static_cast<int*>(reinterpret_cast<void*>(&kk));

        int ln=(1<<(*pn))-1;
        int *pl=static_cast<int*>(reinterpret_cast<void*>(&ln));

        int md=((*pl)+1)/2;
        int *pm=static_cast<int*>(reinterpret_cast<void*>(&md));

        ad *pd=static_cast<ad*>(reinterpret_cast<void*>(new ad()));

        auto lm=mk([&](char c){
            return pd->go(c);
        });

        char rt=
            ((*pn)==1)?
                '0':
                (
                    (*pk)==(*pm)?
                        '1':
                        (
                            (*pk)<(*pm)?
                                findKthBit((*pn)-1,*pk):
                                lm(findKthBit((*pn)-1,(*pl)-(*pk)+1))
                        )
                );

        delete pd;
        return rt;
    }
};