class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        vector<int> odd(n);
        vector<int> even(n);
        for(int i=0;i<n;i++){
            if(i==0){
                odd[i]=0;
                even[i]=nums[i];
                
            }
            else if(i==1){
                odd[i]=nums[i];
                even[i]=nums[i-1];
                
                
            }
            else{
                
                if(i%2==0){
                    even[i]=even[i-1]+nums[i];
                    odd[i]=odd[i-1];
                }
                else{
                    
                    odd[i]=odd[i-1]+nums[i];
                    even[i]=even[i-1];
                }
            }
            
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(i==0){
                if((even[n-1]-even[0])==(odd[n-1]-odd[0])){
                    c++;
                }
                
                
            }
            
            else if(i==n-1){
                
                if(even[n-2]==odd[n-2]){
                    c++;
                }
                
            }
            else{
                if((even[n-1]-even[i]+odd[i-1])==(odd[n-1]-odd[i]+even[i-1])){
                    c++;
                }
                
                
            }
        }
        
        
        return c;
    }
};