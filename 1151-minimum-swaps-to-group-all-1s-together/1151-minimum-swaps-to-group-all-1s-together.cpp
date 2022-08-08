class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n=data.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(data[i]==1)
                c++;
        }
        if(c==0){
            return 0;
        }
        int ans=INT_MAX;
        int count=0;
        int i=0;int j=0;
        while(j<n){
            if(data[j]==0)
            {
                count++;
            }
            if(j-i+1<c){
                
            }
            else{
                ans=min(ans,count);
                if(data[i]==0){
                    count--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};