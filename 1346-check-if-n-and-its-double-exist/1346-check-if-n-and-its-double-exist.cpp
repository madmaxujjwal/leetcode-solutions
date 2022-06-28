class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> ht;
        int n=arr.size();
        for(int i=0;i<n;i++)
            ht[arr[i]]++;
        if(ht[0]>1)
            return true;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(arr[i]!=0&&ht.find(2*arr[i])!=ht.end())
                return true;
        }
        return false;
    }
};