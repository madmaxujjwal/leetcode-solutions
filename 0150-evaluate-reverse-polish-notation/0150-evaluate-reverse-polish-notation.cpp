class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        int n=tokens.size();
        stack<int> st;
        int ans=0;
        int a,b;
        
        for(int i=0;i<n;i++){
            int z;
            string k=tokens[i];
            if(k!="+"&&k!="-"&&k!="*"&&k!="/"){
                z=stoi((tokens[i]));
                st.push(z);
            }
            else{
                a=(st.top());
                st.pop();
                b=(st.top());
                st.pop();
                if(tokens[i]=="+"){
                    ans=b+a;
                }
                else if(tokens[i]=="-"){
                    ans=b-a;
                }
                else if(tokens[i]=="*"){
                    ans=b*a;
                }
                else{
                    ans=b/a;
                }
                st.push(ans);
            }
        }
        
        return st.top();
    }
};