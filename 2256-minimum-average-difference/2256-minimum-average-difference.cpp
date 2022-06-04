class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        long  double s=0;long long int pos=0;
        vector< long double> sum(n);
        sum[0]=nums[0];
        for(int i=0;i<n;i++){
            s=s+nums[i];
        }long long int maxi=10000000000000;
        for(int i=0;i<n;i++){
            if(i!=0){
                sum[i]=sum[i-1]+nums[i];
            }
            long double rest=s-sum[i];
            double avg1=sum[i]/(i+1);
            double avg2;
            if(i!=n-1)
            avg2=rest/(n-i-1);
            else
            avg2=0;    
            int a1=(avg1);
            int a2=(avg2);
           int z=abs(a1-a2);
            if(z<maxi){
                maxi=z;pos=i;
            }
            
        }
       
        return pos;
    }
};