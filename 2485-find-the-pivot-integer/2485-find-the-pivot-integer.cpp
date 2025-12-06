#define ll long long
class Solution {
public:
    int pivotInteger(int n) {
        ll vsqrt = (static_cast<ll>(n) * n + n) / 2;

        int xc = static_cast<int>(sqrt(vsqrt));

        if(static_cast<ll>(xc) * xc == vsqrt){
            return xc;
        } else {
            return -1;
        }
    }
};