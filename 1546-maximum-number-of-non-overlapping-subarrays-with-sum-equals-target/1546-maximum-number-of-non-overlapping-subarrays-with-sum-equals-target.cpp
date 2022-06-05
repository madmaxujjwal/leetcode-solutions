class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> sum(n+1,0);
        
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+nums[i-1];
        }
        unordered_map<int,int> ht;int c=-1;int ans=0;
        for(int i=0;i<=n;i++){
            if(ht.find(sum[i]-target)!=ht.end()){
                int pos=ht[sum[i]-target];
                if(pos>c){
                    ans++;
                    c=i-1;
                }
            }
            ht[sum[i]]=i;
        }
        
        return ans;
    }
};