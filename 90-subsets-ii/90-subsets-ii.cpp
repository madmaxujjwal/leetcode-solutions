class Solution {
public:
    vector<int> subset;
    unordered_map<int,int> ht;
    void rec(vector<int> nums,int i,int n,vector<vector<int>> &ans,set<vector<int>> &st){
        if(i==n){
            vector<int> temp=subset;
            sort(temp.begin(),temp.end());
            
            if(st.find(temp)==st.end())
            {ans.push_back(subset);
            st.insert(temp);}
            
            return;
        }
        rec(nums,i+1,n,ans,st);
        subset.push_back(nums[i]);
        ht[nums[i]]++;
        rec(nums,i+1,n,ans,st);
        subset.pop_back();
        ht[nums[i]]--;
        if(ht.find(nums[i])==ht.end()){
            ht.erase(nums[i]);
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
         vector<vector<int>> ans;
        set<vector<int>> st;
        rec(nums,0,n,ans,st);
       
        return ans;
        
    }
};