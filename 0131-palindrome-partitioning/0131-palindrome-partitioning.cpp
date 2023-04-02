class Solution {
public:
    int n;
    string st;
    vector<vector<string>> ans;
    bool palin(string x){
        int m=x.size();
        for(int i=0;i<m/2;i++){
            if(x[i]!=x[m-1-i])return false;
        }
        return true;
    }
    void rec(int i,vector<string> &a){
        if(i==n){
            ans.push_back(a);
            return ;
        }
        
        string ss="";
        for(int j=i;j<n;j++){
            ss=ss+st[j];
            if(palin(ss)==true)
            { a.push_back(ss);
            rec(j+1,a);
            a.pop_back();
            }
            
            
        }
        
        
        
    }
    vector<vector<string>> partition(string s) {
        
        st=s;
        n=st.size();
        vector<string> a;
        rec(0,a);
        return ans;
        
    }
};