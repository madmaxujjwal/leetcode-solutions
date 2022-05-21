class Solution {
public:
    void search(int i,vector<string> &ans,vector<string> z,int n,string &combination){
        if(combination.size()==n){
            ans.push_back(combination);return;
        }
        for(auto it:z[i]){
            combination.push_back(it);
            search(i+1,ans,z,n,combination);
            combination.pop_back();
        }
    }
    vector<string> expand(string s) {
        vector<string> z;
        int n=s.size();
        bool o=false;
        string temp="";
        for(int i=0;i<n;i++){
            if(s[i]==',')
                continue;
            
            if(s[i]=='{'){o=true;
                
                temp="";
            }
            else if(s[i]=='}'){
                o=false;
                z.push_back(temp);
                temp="";
            }
            else if(o==true){ 
                temp=temp+s[i];
            }
            else{
                string g=string(1,s[i]);
                z.push_back(g);
            }
        }
      /*  if(s[n-1]!='}'){
            z.push_back(temp);
        }*/
        vector<string> ans;
        n=z.size();
        string combination;
        search(0,ans,z,n,combination);
        sort(ans.begin(),ans.end());
        return ans;
    }
};