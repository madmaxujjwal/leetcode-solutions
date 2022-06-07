class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       int n=cardPoints.size();
       vector<int> sum(n+1,0);
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+cardPoints[i-1];
        }
        int s=0;int maxi=-1;
        for(int i=0;i<=k;i++){
            if(i!=0)
            {s=s+cardPoints[n-i];}
            maxi=max(maxi,s+sum[k-i]);
        }
     return maxi;   
    }
};