class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_map<int,int> ht;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ht[nums[i]]++;
        }
        vector<int> arr;
        for(auto it:ht){
            arr.push_back(it.first);
        }
        sort(arr.begin(),arr.end(),greater<int>());
        if(arr.size()<3)
            return arr[0];
        return arr[2];
    }
};