class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        sort(changed.begin(),changed.end());
        vector<int> ans;
        unordered_map<int,int> ht;
        for(int i=0;i<n;i++){
            ht[changed[i]]++;
        }
        for(int i=0;i<n;i++){
            if(ht[changed[i]]==0)continue;
                
            if(changed[i]==0){
                if(ht[0]%2!=0){
                   return {};
                }
              ans.push_back(0);
                ht[0]=ht[0]-2;
                i++;
                
            }
            else{
               
               
                    if(ht[2*changed[i]]==0)
                        return{};
                    
               ans.push_back(changed[i]);
                ht[changed[i]]--;
                ht[changed[i]*2]--;
            }
        }
        
        return ans;
    }
};