#define umipii unordered_map<int, pair<int, int>> 
#define umili unordered_map<int, list<int>> 
#define umilii unordered_map<int, list<int>::iterator>

class LFUCache {
        int cp;
        int mf;

        umipii kv;

        umili fl;

        umilii ki;
public:
    LFUCache(int capacity) {
        cp = capacity;
        mf = 0;
    }
    
    int get(int key) {
        int k = key;
        if(kv.find(k) == kv.end()){
            return -1;
        }
        ifre(k);

        return kv[k].first;
    }
    
    void put(int key, int value) {
        int k = key;
        int v = value;
        if(cp == 0) return;

        if(kv.find(k) != kv.end())
        {
            kv[k].first = v;
            ifre(k);
            return;
        }

        if(kv.size() == cp){
            int evk = fl[mf].back();

            kv.erase(evk);
            ki.erase(evk);
            fl[mf].pop_back();
        }

        mf = 1;
        kv[k] = {v, 1};
        fl[1].push_front(k);
        ki[k] = fl[1].begin();
    }

private:
    void ifre(int key){
        int k = key;
        int cf = kv[k].second;

        fl[cf].erase(ki[k]);

        if(fl[cf].empty()){
            fl.erase(cf);
            if(mf == cf){
                mf++;
            }
        }

        int nf = cf + 1;

        kv[k].second = nf;

        fl[nf].push_front(k);

        ki[k] = fl[nf].begin();
    }
};