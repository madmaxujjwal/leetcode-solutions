class Solution {
public:
    long long int n;
    vector<long long int> adj[100000];
    long long int c;
    long long int maxi;
    long long int dfs(long long int i){
        if(adj[i].size()==0){
            maxi=max(maxi,n-1);
            return 1;
        }
       if(adj[i].size()==1){
           long long int a=dfs(adj[i][0]);
           long long int z=a*(n-1-a);
           if(z<=0)
               z=a;
           maxi=max(maxi,z);
           return a+1;
       }
         if(adj[i].size()==2){
           long long int a=dfs(adj[i][0]);
           long long int b=dfs(adj[i][1]);
          long long int z=a*b*(n-1-a-b);
            if(z<=0)
                z=a*b;
           maxi=max(maxi,z);
             return 1+a+b;
           
       }
        return 0;
    }
     long long int dfs1(long long int i,long long int maxi){
        if(adj[i].size()==0){
            if(maxi==(n-1)){
                c++;
            }
            return 1;
        }
       if(adj[i].size()==1){
           long long int a=dfs1(adj[i][0],maxi);
           long long int z=a*(n-1-a);
           if(z<=0)
               z=a;
           if(maxi==z)
               c++;
           return a+1;
       }
         if(adj[i].size()==2){
           long long int a=dfs1(adj[i][0],maxi);
           long long int b=dfs1(adj[i][1],maxi);
            long long int z=a*b*(n-1-a-b);
             if(z<=0)
                 z=a*b;
           if(maxi==z)
               c++;
             
             return 1+a+b;
           
       }
        return 0;
    }
    
    int countHighestScoreNodes(vector<int>& parents) {
         n=parents.size();
        c=0;
       maxi=INT_MIN;
        for(int i=1;i<n;i++){
            adj[parents[i]].push_back(i);
        }
        long long int ans=dfs(0);
        long long int z=dfs1(0,maxi);
        return c;
        
    }
};