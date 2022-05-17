class Solution {
public:
    bool dfs(int i,vector<int> nums,unordered_map<int,int> &ht,int r,int n,int c){
        ht[i]=-1;
        
        if(i==r||c==n){
            return true;
        }
        int x=(nums[i]+i);
         if( x<0){
                x=n-abs(x)%n;
            }
        if(nums[(x)%n]*nums[i]<0)
        { 
        ht[i]=-1;
        
        return false;}
        if((x)%n==i){
            ht[i]=-1;
            return false;
        }
        return dfs((x)%n,nums,ht,r,n,c+1);
        
    }
    bool circularArrayLoop(vector<int>& nums) {
        unordered_map<int,int> ht;bool v=false;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(ht[i]==-1){
                continue;
            }
            int x=(nums[i]+i);
            if( x<0){
                x=n-abs(x)%n;
            }
            if(nums[(x)%n]*nums[i]<0)
        { 
        ht[i]=-1;
        continue;
        }
         if((x)%n==i){
            ht[i]=-1;
            continue;
        }
          if(dfs((x)%n,nums,ht,i,n,0))
              return true;
        }
        return false;
    }
};