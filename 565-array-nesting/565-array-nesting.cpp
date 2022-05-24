class Solution {
public:
    
    
    int dfs(int i,vector<int>& nums,int a,unordered_map<int,bool> &visited){
        visited[i]=true;
        if(nums[i]==a)
            return 1;
        if(i>=nums.size()){
            return 0;
        }
        
        return 1+dfs(nums[i],nums,a,visited);
        
    }
    int arrayNesting(vector<int>& nums) {
        
        unordered_map<int,bool> visited;
        int n=nums.size();int ans=-1;
        for(int i=0;i<n;i++){
            if(visited[i]!=true)
            ans=max(ans,dfs(i,nums,i,visited));
        }
        return ans;
    }
};