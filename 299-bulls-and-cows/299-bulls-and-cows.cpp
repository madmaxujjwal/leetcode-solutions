class Solution {
public:
    string getHint(string secret, string guess) {
        
        int m=guess.size();
        unordered_map<char,int> ht;
        for(int i=0;i<m;i++){
            ht[guess[i]]++;
        }
        int bulls=0;
        int cows=0;
        for(int i=0;i<m;i++){
            if(secret[i]==guess[i]){
                bulls++;
                ht[guess[i]]--;
                secret[i]='.';
            }
        }
        for(int i=0;i<m;i++){
            if(secret[i]=='.'){
                continue;
            }
            if(ht[secret[i]]>0){
                cows++;
                ht[secret[i]]--;
            }
        }
        
        string ans="";
        ans=ans+to_string(bulls)+'A'+to_string(cows)+'B';
        return ans;
    }
};