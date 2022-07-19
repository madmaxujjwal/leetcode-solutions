class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();long long int s=0;vector<long long int> sum(n+1,0);
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+chalk[i-1];
            s=s+chalk[i-1];
        }
        k=k%s;
        int ind=lower_bound(sum.begin(),sum.end(),k)-sum.begin();
        if(sum[ind]==k){
            return ind;
        }
        return ind-1;
        
        
        
        
    }
};