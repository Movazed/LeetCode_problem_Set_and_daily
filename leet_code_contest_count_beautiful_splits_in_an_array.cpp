#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

#define MOD 1000000007
#define BASE 1000003


#define MODULO(x) ((x) % MOD)
#define ADD_MOD(x, y) (((x) + (y)) % MOD)
#define MUL_MOD(x, y) (((x) * (y)) % MOD)

#define UPDATE_ZARRAY_OUTSIDE_RANGE(index, left, right, ZArray, inputArray, size) {  \
    left = right = index;                                                         \
    while (right < size && inputArray[right - left] == inputArray[right]) {        \
        right++;                                                                   \
    }                                                                             \
    ZArray[index] = right - left;                                                  \
    right--;                                                                       \
}
#define UPDATE_ZARRAY_INSIDE_RANGE(index, left, right, ZArray, inputArray, size) {  \
    ll k = index - left;                                                           \
    ZArray[index] = (ZArray[k] < right - index + 1) ? ZArray[k] : ZArray[index];   \
    if (ZArray[k] >= right - index + 1) {                                          \
        left = index;                                                               \
        while (right < size && inputArray[right - left] == inputArray[right]) {    \
            right++;                                                                 \
        }                                                                            \
        ZArray[index] = right - left;                                               \
        right--;                                                                     \
    }                                                                               \
}

template <typename T>
ll computeHash(ll start, ll end, const vector<T>& hashPrefix, const vector<ll>& powers) {
    return ADD_MOD(hashPrefix[end] - MUL_MOD(hashPrefix[start], powers[end - start]), MOD);
}

template <typename T>
vector<ll> calculateZArray(const vector<T>& inputArray) {
    ll size = inputArray.size();
    vector<ll> ZArray(size, 0);
    ll left = 0, right = 0;
    ll index = 1;

    while (index < size) {
        if (index > right) {
            UPDATE_ZARRAY_OUTSIDE_RANGE(index, left, right, ZArray, inputArray, size);
        } else {
            UPDATE_ZARRAY_INSIDE_RANGE(index, left, right, ZArray, inputArray, size);
        }
        index++;  
    }
    return ZArray;
}


#define INIT_HASHING(arr, size, hashPrefix, powers)         \
    for (ll i = 0; i < size; i++) {                       \
        hashPrefix[i + 1] = ADD_MOD(MUL_MOD(hashPrefix[i], BASE), (arr[i] + 1)); \
        powers[i + 1] = MUL_MOD(powers[i], BASE);         \
    }


#define VERIFY_CONDITIONS(start, end, ZArray, hashPrefix, powers, size, resultCount) { \
    bool condition1 = ((end - start) >= start && ZArray[start] >= start); \
    bool condition2 = ((size - end) >= (end - start)) && (computeHash(start, end, hashPrefix, powers) == computeHash(end, end + (end - start), hashPrefix, powers)); \
    resultCount += (condition1 || condition2) ? 1 : 0; \
}

class Solution  
{
public:
int beautifulSplits (vector<int>& numbers) {
        ll size = numbers.size();
        if (size < 3) return 0;
        ll resultCount = 0;


        vector<ll> ZArray = calculateZArray(numbers);


        vector<ll> hashPrefix(size + 1,0);
        vector<ll> powers(size + 1, 1);

        INIT_HASHING(numbers, size, hashPrefix, powers);

 
        ll start = 1;
        while (start <= size - 2) {
            ll end = start + 1;
            while (end <= size - 1) {

                VERIFY_CONDITIONS(start, end, ZArray, hashPrefix, powers, size, resultCount);
                end++;  }
            start++;  
        }

        return resultCount;
    }
};