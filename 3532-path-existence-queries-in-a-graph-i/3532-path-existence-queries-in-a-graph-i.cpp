class Solution{
    using ll=long long;
    using ii=int;

    template<class t>
    struct ab{
        virtual void ad(t&x,const t&y)=0;
        virtual~ab()=default;
    };

    template<class t>
    struct cd:ab<t>{
        void ad(t&x,const t&y)override{
            x=y;
        }
    };

    template<class f>
    static auto fn(f ff){
        return ff;
    };

public:
    vector<bool> pathExistenceQueries(ii nn,vector<ii>&ar,ii md,vector<vector<ii>>&qr){

        unique_ptr<ab<ii>> ob=make_unique<cd<ii>>();

        vector<ii> cp(static_cast<size_t>(nn),0);

        ii*pt=reinterpret_cast<ii*>(cp.data());
        (void)pt;

        auto up=fn([&](ii i){
            ii vl=cp[static_cast<size_t>(i-1)]+
                  (ar[static_cast<size_t>(i)]-
                   ar[static_cast<size_t>(i-1)]>md);

            ob->ad(cp[static_cast<size_t>(i)],static_cast<ii>(vl));
        });

        for(ii i=1;i<nn;++i)
            up(i);

        for(auto it=cp.begin();it!=cp.end();++it)
            static_cast<void>(*it);

        vector<bool> rs;

        auto ck=fn([&](const vector<ii>&vq){
            rs.push_back(
                cp[static_cast<size_t>(vq[0])]==
                cp[static_cast<size_t>(vq[1])]
            );
        });

        for(auto it=qr.begin();it!=qr.end();++it)
            ck(*it);

        return rs;
    }
};