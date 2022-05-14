class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> ht;
       
        for(int i=0;i<n;i++)
            ht[nums[i]+k]++;
        int z=0;
        for(auto it:ht){
            if(it.second>1)
                z++;
        }
        for(int i=0;i<n;i++)
            ht[nums[i]+k]=1;
        int ans=0;
        for(auto it:ht){
            if(it.second>0){
                int d=it.first-k;
            
            if(ht.find(d)!=ht.end())
                ans++;}
        }
        if(k==0)
            return z;
        return ans;
    }
};