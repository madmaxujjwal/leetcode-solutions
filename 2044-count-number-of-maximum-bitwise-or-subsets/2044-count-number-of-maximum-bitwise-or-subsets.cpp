class Solution {
public:
    
    int maxi;
    int n;
    vector<int> num;
    int c;
    void rec(int i,vector<int> &a){
        
        if(i==n){
            int v=0;
            for(auto it:a){
                v=v|it;
            }
            if(v==maxi){
                c++;
            }
            return ;
        }
        a.push_back(num[i]);
        rec(i+1,a);
        a.pop_back();
        rec(i+1,a);
        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        maxi=INT_MIN;
        maxi=0;
        n=nums.size();
        num=nums;
        c=0;
        for(int i=0;i<n;i++){
            maxi=maxi|nums[i];
        }
        vector<int> a;
        rec(0,a);
        return c;
    }
};