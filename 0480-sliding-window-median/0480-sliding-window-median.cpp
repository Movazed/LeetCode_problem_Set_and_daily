class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
        multiset<double>l,r;
        vector<double>res;
        bool is_K_Even=(k%2==0);
        
        auto rebalance = [&](){
            while(l.size()>r.size()+1){
                r.insert(*l.rbegin());
                l.erase(prev(l.end()));
            }
            while(r.size()>l.size()){
                l.insert(*r.begin());
                r.erase(r.begin());
            }
        };

        for(int i=0;i<k;i++){
            if(l.empty() || arr[i]<=*l.rbegin()){
                l.insert(arr[i]);
            }else{
                r.insert(arr[i]);
            }
            rebalance();
        }

        for(int i=k;i<=n;i++){
            double median=0.0;

            if(is_K_Even){
                median= (*l.rbegin() + *r.begin())/2;
            }else{
                median=*l.rbegin();
            }
            res.push_back(median);

            if(l.find(arr[i - k]) != l.end())
                l.erase(l.find(arr[i - k]));
            else
                r.erase(r.find(arr[i - k]));
            rebalance(); 
    
            if(i==n) break;
            if(l.empty() || arr[i]<=*l.rbegin()){
                l.insert(arr[i]);
            }else{
                r.insert(arr[i]);
            }
            rebalance();

        }
        
    return res;
    }
};