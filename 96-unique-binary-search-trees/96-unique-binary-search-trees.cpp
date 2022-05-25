class Solution {
public:
    int rec(int n,unordered_map<int,int> &ht){
        if(ht.find(n)!=ht.end())
            return ht[n];
        if(n==1)
            return 1;
        else if(n==0)
            return 1;
        else if(n==2)
            return 2;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=rec(i,ht)*rec(n-1-i,ht);
        }
        return ht[n]=ans;
        
    }
    int numTrees(int n) {
        unordered_map<int,int> ht;
        return rec(n,ht);
    }
};