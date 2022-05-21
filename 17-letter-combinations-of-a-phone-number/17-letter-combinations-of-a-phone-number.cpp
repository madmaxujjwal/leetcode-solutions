class Solution {
public:
    void search(int i,vector<string> &ans,string &z,int n,string digits,vector<vector<char>> m){
        if(z.size()==n){
            ans.push_back(z);
            return;
        }
        for(auto it:m[digits[i]-'0']){
            z.push_back(it);
            search(i+1,ans,z,n,digits,m);
            z.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> m={{'_'},{'_'},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        int n=digits.size();
        if(n==0)
            return {};
        vector<string> ans;
        string z="";
        search(0,ans,z,n,digits,m);
        return ans;

    }
};