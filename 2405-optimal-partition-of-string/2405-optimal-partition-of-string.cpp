class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        int ans=1;
        unordered_map<char,int> ht;
        
        for(int i=0;i<n;i++){
            if(ht[s[i]]>0){
                ans++;
                ht.clear();
               
            }
             ht[s[i]]++;
            
        }
        return ans;
    }
};