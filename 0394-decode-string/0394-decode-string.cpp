class Solution {
public:
    
    string mulp(string s,int x){
        string ans="";
        for(int i=1;i<=x;i++){
            ans=ans+s;
        }
        return ans;
    }
    string decodeString(string s) {
        int n=s.size();
        int k=0;
        string ans="";
        string z="";
        int net=0;
        bool v=false;
        for(int i=0;i<n;i++){
            if(s[i]=='[')net++;
            if(s[i]==']')net--;
            if(s[i]>='0'&&s[i]<='9'&&v==false){
                k=k*10+(s[i]-'0');
            }
            else if(v&&net>0){
                z=z+s[i];
                //return z;
            }
            else if(s[i]==']'){
               v=false;
                
                if(k==0)k++;
                ans=ans+mulp(decodeString(z),k);
                z="";
                
                k=0;
            }
            else if(s[i]=='['){
                v=true;
                ans=ans+z;
                
                z="";
            }
            else{
                z=z+s[i];
            }
            
        }
        
        ans=ans+z;
        
        return ans;
    }
};