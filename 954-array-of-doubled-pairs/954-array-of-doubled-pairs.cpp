class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> ht;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            ht[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(ht[arr[i]]==0)continue;
            if(arr[i]==0){
                if(ht[0]%2!=0){
                    return false;
                }
                ht[0]=ht[0]-2;
                i++;
                
            }
            else if(arr[i]>0){
                if(ht[2*arr[i]]==0)
                    return false;
                ht[arr[i]]--;
                ht[2*arr[i]]--;
            }
            else{
                if(abs(arr[i])%2!=0||ht[arr[i]/2]==0)return false;
                 ht[arr[i]]--;
                ht[arr[i]/2]--;
            }
        }
        return true;
    }
};