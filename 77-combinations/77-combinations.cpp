class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;
    void search(int k,int i,int n){
        
        if(subset.size()==k&&i<=(n+1)){
            ans.push_back(subset);
            return ;
        }
        if(i>=n+1){
            return;
        }
        search(k,i+1,n);
        subset.push_back(i);
        search(k,i+1,n);
        subset.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        search(k,1,n);
        return ans;
    }
};