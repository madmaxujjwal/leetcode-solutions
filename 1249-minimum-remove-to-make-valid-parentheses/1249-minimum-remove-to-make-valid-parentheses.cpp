class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        int n=s.size();
        int o=0;int c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                o++;
            }
            else if(s[i]==')'){
                c++;
            }
            if(c>o){
                c--;
                s[i]='*';
            }
            
        }
        o=o-c;
        for(int i=n-1;i>=0;i--){
            if(o<=0)
                break;
            if(s[i]=='('){
                s[i]='*';
                o--;
            }
        }
        
       
      for(int i=0;i<n;i++){
          if(s[i]=='*'){
              
          }
          
          else{
              ans.push_back(s[i]);
          }
      }
        return ans;
    }
};