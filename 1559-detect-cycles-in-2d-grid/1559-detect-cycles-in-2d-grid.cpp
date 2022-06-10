class Solution {
public:
    vector<int> size;
    vector<int> parent;
    vector<int> visited;
    int m;
    int n;
    void make_set(int a){
        parent[a]=a;
        size[a]=1;
    }
    int find(int a){
        if(parent[a]==a){
            return a;
        }
        return parent[a]=find(parent[a]);
    }
    void unio(int a,int b){
        if(size[a]<size[b]){
               swap(a,b);
        }
        parent[b]=a;
         size[a]+=size[b];
    }
   bool dfs(vector<vector<char>>& grid,int i,int j,int pi,int pj){
       visited[i*m+j]=true;
       if(pi!=-1||pj!=-1){
       int a=find(pi*m+pj);
       int b=find(i*m+j);
       if(a==b){
           return true;
       }
       else{
           unio(a,b);
           
       }
       }
       bool w=false;bool x=false;bool y=false;bool z=false;
       
       if(i>0){
           if((grid[i-1][j]==grid[i][j])&&((i-1)!=pi||(j!=pj)))
             w=  dfs(grid,i-1,j,i,j);
            }
       if(i<n-1){
           if((grid[i+1][j]==grid[i][j])&&((i+1)!=pi||(j!=pj)))
              x= dfs(grid,i+1,j,i,j);
       }
       if(j>0){
            if((grid[i][j-1]==grid[i][j])&&((i)!=pi||((j-1)!=pj)))
              y= dfs(grid,i,j-1,i,j);
       }
       if(j<m-1){
            if((grid[i][j+1]==grid[i][j])&&((i)!=pi||((j+1)!=pj)))
             z=dfs(grid,i,j+1,i,j);
       }
       return w|x|y|z;
   }
    bool containsCycle(vector<vector<char>>& grid) {
         n=grid.size();
         m=grid[0].size();
       size.resize(n*m);
       parent.resize(n*m);
       visited.resize(n*m);
       // memset(visited,false,sizeof(visited));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                make_set(i*m+j);
        }bool x=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int pos=i*m+j;
                if(visited[pos]==true){
                    continue;
                }
                x= dfs(grid,i,j,-1,-1);
                if(x){
                   return true;
                }
            }
        }
        return false;
    }
};