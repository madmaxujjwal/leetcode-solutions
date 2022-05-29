class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> ht;
        int n=wall.size();int s=0;
        for(auto it:wall[0]){
            s+=it;
        }
        for(int i=0;i<n;i++){
            int sum=0;
            for(auto it:wall[i]){
                sum+=it;
                if(sum!=s)
                ht[sum]++;
            }
        }
        int ans=0;
        for(auto it:ht){
            ans=max(ans,it.second);
        }
        return n-ans;
        
    }
};