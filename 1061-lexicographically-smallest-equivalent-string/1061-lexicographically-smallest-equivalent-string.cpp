class Solution {
public:
    unordered_map<char,char> ht;
   void make_set(char a){
        ht[a]=a;
    }
    char find_set(char a){
        if(ht[a]==a)
            return a;
        return ht[a]=find_set(ht[a]);
    }
    void make_union(char a ,char b)
    {
        a=find_set(a);
        b=find_set(b);
        if(a==b)
            return;
        if(a>b)
            swap(a,b);
        ht[b]=a;
    }   
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(char ch='a';ch<='z';ch++){
            make_set(ch);
        }
        for(int i=0;i<s1.size();i++){
            make_union(s1[i],s2[i]);
        }
        
        string ans="";
        for(int i=0;i<baseStr.size();i++){
            ans+=find_set(baseStr[i]);
        }
        return ans;
    }
};