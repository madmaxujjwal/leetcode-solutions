class Solution {
public:
    void search(vector<vector<int>> &ans,vector<int> &combination,vector<int> candidates,int target,int &s,set<vector<int>> &st){
        if(s>target){
            return;
        }
        if(s==target){
            vector<int> z=combination;
            sort(z.begin(),z.end());
            if(st.find(z)==st.end())
            
            {st.insert(z);ans.push_back(combination);
            }
            return;
        }
        for(int i=0;i<candidates.size();i++){
            if(s+candidates[i]>target){
                continue;
            }
            s=s+candidates[i];
            combination.push_back(candidates[i]);
            search(ans,combination,candidates,target,s,st);
            s=s-candidates[i];
            combination.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        int sum=0;
        set<vector<int>> st;
        search(ans,combination,candidates,target,sum,st);
        return ans;
        
    }
};