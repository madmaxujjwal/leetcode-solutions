class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        vector<int> one;vector<int> two;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(nums[i]%3==1){
                one.push_back(nums[i]);
            }
            else if(nums[i]%3==2){
                two.push_back(nums[i]);
            }
        }
        sort(one.begin(),one.end());
        if(one.size()>=2){
        for(int i=0;i<one.size()-1;i++){
            two.push_back(one[i]+one[i+1]);
        }
        }
        sort(two.begin(),two.end());
        if(sum%3==0){
            return sum;
        }
        else if(sum%3==1){
            if(one.size()==0&&two.size()<2)
                return 0;
            if(one.size()==0){
                return two[0]+two[1];
            }
            int mini=one[0];
            if(two.size()>1){
                mini=min(mini,two[0]+two[1]);
            }
            return (sum-mini);
        }
        else {
            if(two.size()==0){
                return 0;
            }
            return sum-two[0];
        }
        return sum;
    }
};