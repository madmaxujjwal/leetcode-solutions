class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        stack<char> st;int c=0;
        for(int i=0;i<n;i++){
         if(s[i]==')'){
             if(st.size()){
                 st.pop();
             }
             else{
                 c++;
             }
         }   
            else{
                st.push('(');
            }
        }
        c+=st.size();
        return c;
    }
};