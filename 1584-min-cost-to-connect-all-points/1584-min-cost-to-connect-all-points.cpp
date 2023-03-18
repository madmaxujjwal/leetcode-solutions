class Solution {
public:
int n;
vector<int> parent;
   
    int find(int i){
        if(parent[i]==i)return i;

        return parent[i]=find(parent[i]);
    }

    bool unioni(int x,int y){
       x=find(x);
       y=find(y);
       if(x==y)
         return false;
       
       parent[y]=x;
         return true;
    }

    
    int minCostConnectPoints(vector<vector<int>>& points) {
         n=points.size();
       //  parent.resize(n);
        vector<vector<int>> adj(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
      
         for(int j=0;j<n;j++){

             adj[i][j]=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);



         }

        }
      
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        //return -1;
        
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>> >,greater<pair<int,pair<int,int>> > >pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pq.push({adj[i][j],make_pair(i,j)});
            }
        }
        int ans=0;
       //return pq.size();
       while(pq.size()>0){
        
          int x=pq.top().second.first;
          int y=pq.top().second.second;
          if(unioni(x,y)){
            ans+=pq.top().first;
          }
        
           pq.pop();
       }
       return ans;
    }
};