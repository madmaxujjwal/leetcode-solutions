class Solution {
public:
    int count(string s){
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')
                c++;
        }
        c=c+1;
        return c;
        
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n=messages.size();
        string ans="";
        int maxi=INT_MIN;
        unordered_map<string,int> ht;
        for(int i=0;i<n;i++){
            int no_of_words=count(messages[i]);
            ht[senders[i]]+=no_of_words;
            
        }
        for(auto it:ht){
            if(maxi<it.second){
                maxi=it.second;
                ans=it.first;
            }
            else if(maxi==it.second&&ans<it.first){
                ans=it.first;
            }
        }
        return ans;
    }
};