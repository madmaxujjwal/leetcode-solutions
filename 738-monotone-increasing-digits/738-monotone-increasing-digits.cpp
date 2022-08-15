class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string a=to_string(n);
        int len=a.size();int x=-1;
        string ans;
       int p=0;
        for(int i=0;i<len-1;i++){
            
            if(a[i]>a[i+1]){
                x=p;break;
            }
            if(a[i]!=a[i+1]){
                p=i+1;
            }
        }
        if(x==-1){
            return stoi(a);
        }
        ans=a.substr(0,x); 
        ans=ans+char(int(a[x])-1);
        for(int i=x+1;i<len;i++){
            ans+='9';
        }
    return stoi(ans);
    }
};