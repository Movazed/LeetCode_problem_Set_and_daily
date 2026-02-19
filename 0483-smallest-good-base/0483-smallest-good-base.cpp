class Solution {
public:
    string smallestGoodBase(string n) {
        const long long num = stoll(n);
        for(int m = log2(num); m >= 2; --m){
            const int k = pow(num , 1.0 / m); 
            long long sum = 1, prod = 1;
            for(int i = 0; i < m; ++i){
                prod *= k;
                sum += prod;
            }
            if(sum == num) return to_string(k);
        }
        return to_string(num - 1);
    }
};