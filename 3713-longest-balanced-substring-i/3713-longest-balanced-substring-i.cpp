#include <functional>
#include <memory>
#define lp(i, n) for(int i = 0; i < n; i++)
#define lpp(i, s, n) for(int i = s; i < n; i++)

class solution {
    using fn = std::function<bool(const int*, int, int)>;
    using ptr = void*;
    
    template<typename t>
    t* allocate(int sz) {
        return reinterpret_cast<t*>(operator new(sz * sizeof(t)));
    }
    
    template<typename t>
    void deallocate(t* p) {
        operator delete(reinterpret_cast<ptr>(p));
    }
    
    fn chk = [this](const int* fr, int mx, int dc) -> bool {
        return (mx * dc == std::distance(fr, fr + 26)) ? true : 
               (dc == 1) ? true : false;
    };
    
public:
    int longestbalanced(std::string s) {
        int n = s.length();
        int rs = 0;
        
        lp(i, n) {
            int* fr = allocate<int>(26);
            lp(j, 26) fr[j] = 0;
            
            int mx = 0, dc = 0;
            
            lpp(j, i, n) {
                int ix = s[j] - 'a';
                fr[ix]++;
                dc = (fr[ix] == 1) ? dc + 1 : dc;
                mx = (fr[ix] > mx) ? fr[ix] : mx;
                
                int ln = j - i + 1;
                rs = ((mx * dc == ln) || (dc == 1)) ? 
                     ((ln > rs) ? ln : rs) : rs;
            }
            
            deallocate(fr);
        }
        
        return rs;
    }
};

class wrapper {
    std::unique_ptr<solution> sl;
    
public:
    wrapper() : sl(std::make_unique<solution>()) {}
    
    int operator()(std::string s) {
        return sl->longestbalanced(s);
    }
};

class Solution {
public:
    int longestBalanced(string s) {
        auto oo = wrapper();
        return oo(s);
    }
};