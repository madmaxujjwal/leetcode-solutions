class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> ht;
        for(int i=0;i<n;i++){
            ht[(arr[i]%k+k)%k]++;
        }
        if(ht[0]%2!=0){
            return false;
        }
        for(int i=1;i<=k/2;i++){
            if(ht[i]!=ht[k-i]){
                return false;
            }
        }
        return true;
    }
};