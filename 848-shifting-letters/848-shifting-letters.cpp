class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long int n=shifts.size();
        unordered_map<long long int,char> ht;
        for(char ch='a';ch<='z';ch++){
            ht[ch-'a']=ch;
        }
        long long int sum=0;
        for(int i=n-1;i>=0;i--){
           long long int z=s[i]-'a';
            sum=sum+shifts[i];
            z=(z+sum)%26;
            s[i]=ht[z];
            
        }
        return s;
    }
};