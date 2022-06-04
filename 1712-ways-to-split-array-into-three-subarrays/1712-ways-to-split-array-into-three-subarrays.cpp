class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int m=1e9+7;
        int n=nums.size();
        int s=0;
        vector<int> sum(n);
        sum[0]=nums[0];
        for(int i=0;i<n;i++){
            s+=nums[i];
        }int c=0;
        for(int i=0;i<n;i++){
            if(i!=0){
                sum[i]=sum[i-1]+nums[i];
            }
        }
          for(int i=0;i<n;i++){
        
            double rest=s-sum[i];
           int a;
            int b;
            a=2*sum[i];
            b=sum[i]+rest/2;
            int ip=lower_bound(sum.begin()+i+1,sum.end(),a)-sum.begin();
            int jp=upper_bound(sum.begin()+i+1,sum.end(),b)-sum.begin();
            if(jp==n){
                jp=n-1;
            }
              if(ip<=i){
                  ip=i+1;
              }
           
                jp--;
            
         
          
            if(ip<=jp)
            c=(c+(jp%m-ip%m+1%m)%m)%m;
            
            
        }
        return c;
    }
};