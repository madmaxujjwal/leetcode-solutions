class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n=nums.size();
        vector<int> ans;
        int i=-1;
        int j=n-1;
        if(a==0){
        if(b>0)
        {
            for(int z=0;z<n;z++){
                ans.push_back(b*nums[z]+c);
            }
        }
        else{
            for(int z=n-1;z>=0;z--){
                ans.push_back(b*nums[z]+c);
            }
        }
            return ans;
        }
        double B=b;
        double A=a;
        double v=-1*0.500000000000000000000*(B/(A));
        for(int a=0;a<n;a++){
            if(nums[a]>v){
                j=a;break;
            }
        }
        for(int a=n-1;a>=0;a--){
            if(nums[a]<=v){
                i=a;
                break;
            }
        }
        while(i>=0&&j<=n-1){
            if(abs(v-nums[i])<=abs(v-nums[j])){
                ans.push_back(a*nums[i]*nums[i]+b*nums[i]+c);
                i--;
            }
            else{
                  ans.push_back(a*nums[j]*nums[j]+b*nums[j]+c);
                j++;
            }
            
        }
        for(int z=i;z>=0;z--){
             ans.push_back(a*nums[z]*nums[z]+b*nums[z]+c);
        }
        for(int z=j;z<n;z++){
            ans.push_back(a*nums[z]*nums[z]+b*nums[z]+c);
        }
        if(a<0)
            reverse(ans.begin(),ans.end());
        for(int i=0;i<n-1;i++){
            if(ans[i]>ans[i+1]){
                swap(ans[i],ans[i+1]);
            }
        }
        return ans;
    }
        
    
};