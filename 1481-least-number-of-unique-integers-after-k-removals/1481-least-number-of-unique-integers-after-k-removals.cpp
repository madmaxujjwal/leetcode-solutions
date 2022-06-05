class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> ht;
        for(int i=0;i<n;i++){
            ht[arr[i]]++;
        }
        vector<int> z;int sum=0;
        for(auto it:ht){
            z.push_back(it.second);
            sum=sum+it.second;
        }
        sort(z.begin(),z.end());
        if(sum<=k){
            return 0;
        }
    
        sum=0;
        for(int i=0;i<z.size();i++){
            sum=sum+z[i];
            if(sum>k){
                return z.size()-i;
            }
            
        }
        return 0;
    }
};