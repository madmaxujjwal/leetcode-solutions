class Solution {
public:
    
    void search(vector<vector<int>> &ans,vector<int> &z,vector<int> &present,int &s,int k,int n, set<vector<int>> &st){
        if(z.size()==k){
            if(s==n){vector<int> f=z;
                sort(f.begin(),f.end());
                if(st.find(f)==st.end())
                {  ans.push_back(f);
                st.insert(f);}
                     
                return;
            }
            else{
                return;
            }
        }
        for(int i=1;i<=9;i++){
            if(present[i]==1||((s+i)>n))
                continue;
            present[i]=1;
            z.push_back(i);
            s+=i;
            search(ans,z,present,s,k,n,st);
            present[i]=0;
            z.pop_back();
            s-=i;            

            
        }
    }
    
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> z;
        set<vector<int>> st;
        vector<int> present(10,0);
        int s=0;
        search(ans,z,present,s,k,n,st);
        return ans;
    }
};