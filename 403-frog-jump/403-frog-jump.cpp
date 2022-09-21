class Solution {
public:
    unordered_map<int,int> present;
    map<pair<int,int>,int> dp;
    int f;int n;
    int rec(int x,int y){
        if(y==0)return false;
        
        if(present[x]==0)return false;
        if(x==f)return true;
        if(dp.find({x,y})!=dp.end())return dp[{x,y}];
        return  dp[{x,y}]=rec(x+y+1,y+1)|rec(x+y,y)|rec(x+y-1,y-1);
        
    }
    bool canCross(vector<int>& stones) {
        
        
        
        n=stones.size();
        f=stones[n-1];
        for(int i=0;i<n;i++){
            present[stones[i]]++;
        }
        return rec(1,1);
    }
};