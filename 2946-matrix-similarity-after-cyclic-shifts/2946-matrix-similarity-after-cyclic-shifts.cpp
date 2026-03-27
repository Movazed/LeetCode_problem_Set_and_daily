class ax {
public:
    virtual bool ex(std::vector<std::vector<int>> &mat, int k) = 0;
    virtual ~ax() {}
};

template<class T>
class bx : public ax {
public:

    bool ex(std::vector<std::vector<int>> &mat, int k) override {
        int m = (int)mat.size();
        int n = (int)mat[0].size();

        k %= n;

        for (int i = 0; i < m; i++) {
            const std::vector<int> &row = mat[i];

            for (int j = 0; j < n; j++) {
                const int *a = &row[j];

                int idx;
                if ((i & 1) == 0) {
                    // even row → left rotate
                    idx = (j + k) % n;
                } else {
                    // odd row → right rotate
                    idx = (j - k + n) % n;
                }

                const int *b = &row[idx];

                if (*a != *b) return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool areSimilar(std::vector<std::vector<int>>& mat, int k) {

        std::unique_ptr<ax> obj((ax*)new bx<int>());
        return obj->ex(mat, k);
    }
};