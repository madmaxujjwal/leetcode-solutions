class Solution {
public:
    
    void search(int i,int n,vector<string> &ans,string &z,int &o,int &c){
        if(o>n||c>n||i>2*n){
            return;
        }
        if(o==n&&c==n&&i==(2*n)){
            ans.push_back(z);
            return ;
        }
        if(o<n&&c<n){
            z[i]='(';
            o++;
            search(i+1,n,ans,z,o,c);
            z[i]='.';
            o--;
        }
           if(o>c&&c<n){
               z[i]=')';
               c++;
               search(i+1,n,ans,z,o,c);
               c--;
               z[i]='.';
           }
        
        
    }
           
    
    vector<string> generateParenthesis(int n) {
      vector<string> ans;
        string z="";
        for(int i=0;i<2*n;i++){
            z=z+'.';
        }
        int o=0;
        int c=0;
        search(0,n,ans,z,o,c);
        return ans;
        
    }
};