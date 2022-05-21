class Solution {
public:
    void search(int i,vector<string> &ans,string &z,int n,string s){
       
        if(z.size()==n){
            ans.push_back(z);return;
        }
        if((int)s[i]>=97&&(int)s[i]<=122)
            {
        z.push_back(s[i]);
        search(i+1,ans,z,n,s);
        z.pop_back();
        z.push_back(toupper(s[i]));
        search(i+1,ans,z,n,s);
        z.pop_back();}
        else if((int)s[i]>=65&&(int)s[i]<=90){
            z.push_back(s[i]);
        search(i+1,ans,z,n,s);
        z.pop_back();
        z.push_back(tolower(s[i]));
        search(i+1,ans,z,n,s);
        z.pop_back();
        }
        else{
            z.push_back(s[i]);
        search(i+1,ans,z,n,s);
        z.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        vector<string> ans;
        string z;
        search(0,ans,z,n,s);
        return ans;
    }
};