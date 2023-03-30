class Solution {
public:
    string st;
    bool rec(int i,int j){
        
        
        if(i==j)return true;
        if(j-i==1){
            if(st[i]==st[j])return true;
            else
                return false;
        }
        return (st[i]==st[j])&&rec(i+1,j-1);
    }
    int countSubstrings(string s) {
        st=s;int c=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            
            
            for(int j=i;j<n;j++){
                
                if(rec(i,j)==true){
                    c++;
                }
            }
        }
        return c;
    }
};