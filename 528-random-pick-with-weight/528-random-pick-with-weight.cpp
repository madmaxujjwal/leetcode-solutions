class Solution {
public:
    vector<int> z;
    vector<int> sum;
    Solution(vector<int>& w) {
        z=w;int s=0;
        for(int i=0;i<w.size();i++){
            s+=z[i];
            sum.push_back(s);
            
        }
        
    }
    
    int pickIndex() {
        int n=z.size();
        int p=sum.back()*(((float)rand())/RAND_MAX);
        int index=upper_bound(sum.begin(),sum.end(),p)-sum.begin();
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */