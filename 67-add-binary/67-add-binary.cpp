class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int n=a.size();
        int m=b.size();int i=0;int j=0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());int c=0;
        while(i<n||j<m){
            int x=0;
            int y=0;
            if(i<n)
                x=a[i]-'0';
            if(j<m)
                y=b[j]-'0';
           int z=x+y+c;
           ans+=char(z+48);
            if(z>=2){
                c=1;
            }
            else{
                c=0;
            }
            i++;
            j++;
            
        }
        if(c==1){
            ans+='1';
        }
       string k="";
        for(int i=0;i<ans.size();i++){
            char ch=ans[i];
            if(ch=='2'){
                ch='0';
            }
            else if(ch=='3'){
                ch='1';
            }
            k=ch+k;
        }
        return k;
        
    }
};