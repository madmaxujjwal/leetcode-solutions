class Solution {
public:
    bool makePalindrome(string s) {
        int n=s.size();
        int c=0;
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i]){
                c++;
            }
        }
        if(c>2)
            return false;
        return true;
        
    }
};