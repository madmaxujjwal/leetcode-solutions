class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                st.push(s[i]);
            }
             else{
                 if(st.size()){
                     st.pop();
                 }
             }
        }
        int ans=(st.size()+1)/2;
        return ans;
    }
};