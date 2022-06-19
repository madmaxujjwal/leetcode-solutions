class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> ht;int z=s1.size();
        for(int i=0;i<s1.size();i++){
            ht[s1[i]]++;
        }
        unordered_map<char,int> ht1;
        int i=0;int j=0;
        int n=s2.size();
        while(j<n){
             ht1[s2[j]]++;
            if(j-i+1<z){
               
                j++;
            }
            else{
                if(ht1==ht)
                    return true;
                ht1[s2[i]]--;
                if(ht1[s2[i]]==0)
                    ht1.erase(s2[i]);
                i++;
                j++;
            }
        }
        return false;
    }
};