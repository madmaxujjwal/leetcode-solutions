class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        stack<char> st;int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                st.pop();
                
            }
           if(maxi<st.size())
               maxi=st.size();
        }
        return maxi;
    }
};