class Solution {
public:
    
    void dfs(unordered_map<int,vector<int>> &ht,int i, vector<int> &ans)
    { 
        ans.push_back(i);
        
        for(auto &it:ht[i]){
           
                
             
                
                dfs(ht,it,ans);
            }
        }
    
    
    
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        
        int n=pid.size();
        unordered_map<int,vector<int>> ht;
        for(int i=0;i<n;i++){
            ht[ppid[i]].push_back(pid[i]);
        }
        
       vector<int> ans;
        dfs(ht,kill,ans);
        return ans;
        
    }
};