class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        
        int maxi;
        int l=1;
        int h=100000;
        int n=ribbons.size();int ans=0;
        while(l<=h){
            maxi=(l+h)/2;bool v=false;int sum=0;
            for(int i=0;i<n;i++){
                sum=sum+ribbons[i]/maxi;
                if(sum>=k){
                    v=true;break;
                }
            }
            if(v){
                ans=maxi;
                l=maxi+1;
            }
            else{
                h=maxi-1;
            }
        }
        return ans;
        
    }
};