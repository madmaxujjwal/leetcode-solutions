class Solution {
public:
    int sum;
    int ans;
    int d;
    int m;
    int n;int tar;vector<int> t;
    void fun(int i){
        
        if(i==m){
            if(((abs(sum-tar))==d&&sum<ans)||(abs(sum-tar))<d){
                ans=sum;
                d=abs(sum-tar);
            }
            return ;
        }
        for(int j=0;j<3;j++){
            sum+=j*t[i];
            fun(i+1);
            sum-=j*t[i];
            
        }
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
         sum=0;int v;tar=target;bool g=false;
         ans=INT_MAX;
        d=INT_MAX;
        n=baseCosts.size();
        m=toppingCosts.size();t=toppingCosts;
        for(int i=0;i<n;i++){
            sum=baseCosts[i];ans=INT_MAX;
            d=INT_MAX;
            fun(0);
            if(g==false){
                v=ans;
                g=true;
            }
            
            if((abs(ans-target)<abs(v-target))||((abs(ans-target)==abs(v-target))&&(v>ans))){
                v=ans;
                
            }
           
        }
        return v;
        
    }
};