class Solution {
public:
    void reverse(vector<char>& s,int i,int j){
        int st=i;int en=j;
        while(st<en){
            swap(s[st],s[en]);
            st++;en--;
        }
    }
    void reverseWords(vector<char>& s) {
        int n=s.size();
        reverse(s,0,n-1);
       int st=0;
        
        for(int i=0;i<=n;i++){
            if(i==n){
                reverse(s,st,n-1);
                break;
            }
            if(s[i]==' '){
                reverse(s,st,i-1);
                
                st=i+1;
            }
        }
       
    }
};