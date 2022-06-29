class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> ht;
        int n=nums.size();
        vector<int> temp(n);
        for(int i=0;i<n;i++)
            temp[i]=(nums[i]);
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++){
            if(ht.find(temp[i])==ht.end()){
                ht[temp[i]]=i;
            }
            
        }
        for(int i=0;i<n;i++){
            nums[i]=ht[nums[i]];
        }
        return nums;
    }
};