class Solution {
public:
    vector<int> num;
    unordered_map<string,int> dp;
    int rec(int i,int sum,int l){
        if(i==-1){
            if(sum==0&&l==0)return 1;
            else
                return 0;
        }
        // if(l==0){
        //     if(sum==0)return 1;
        //     else
        //         return 0;
        // }
        // if(sum==0){
        //     if(l==0)return 1;
        //     else
        //         return 0;
        // }
         string k=to_string(i)+" "+to_string(sum)+" "+to_string(l);
        if(dp.find(k)!=dp.end())return dp[k];
        // if(i>=0&&sum>=0&&l>=0)
        //     return dp[k];
        if(sum<0||l<0||i<-1)return 0;
        return dp[k]=rec(i-1,sum-num[i],l-1)||rec(i-1,sum,l);
        
        
    }
    bool splitArraySameAverage(vector<int>& nums) {
        num=nums;int n=nums.size();
        int S=0;
        for(int i=0;i<nums.size();i++){
            S+=nums[i];
        }
        if(S==0&&n>1)return true;
        if(S==0&&n==1)return false;
      
        for(int l=1;l<nums.size();l++){
          
            int a=l;
            int b=nums.size()-l;
            if((a*S)%(a+b)==0){
                double sum=((a*S)/(a+b));
                //if(sum==18)return true;
                double su=S-sum;int z=l;
                if(su<sum)
                { sum=su;
                 z=n-l;
                }
                if(rec(nums.size()-1,sum,z)==1)return true;
            }
           
        }
        return false;
    }
};