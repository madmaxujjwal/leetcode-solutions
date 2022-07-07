class Solution {
public:
    map<pair<int,bool>,int> dp;
    int rec(vector<int>&nums1,vector<int>&nums2,int n,bool c){
        if(dp.find({n,c})!=dp.end())
            return dp[{n,c}];
        if(n==0)
            return 0;
        bool c1=(nums1[n-1]<nums1[n])&&(nums2[n-1]<nums2[n]);
        bool c2=(nums2[n-1]<nums1[n])&&(nums1[n-1]<nums2[n]);
        if(c==true){
            if(c1&&c2){
                return dp[{n,c}]=min(rec(nums1,nums2,n-1,c),1+rec(nums1,nums2,n-1,!c));
            }
            else if(c1){
                return dp[{n,c}]=(rec(nums1,nums2,n-1,c));
            }
            else
                return dp[{n,c}]=1+rec(nums1,nums2,n-1,!c);
        }
        else{
            if(c1&&c2){
                return dp[{n,c}]=min(rec(nums1,nums2,n-1,true),1+rec(nums1,nums2,n-1,false));
            }
            else if(c2){
                return dp[{n,c}]=(rec(nums1,nums2,n-1,true));
            }
            else
                return dp[{n,c}]=1+rec(nums1,nums2,n-1,false);
        }
        
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int inf=INT_MAX;
        nums1.push_back(inf);
        nums2.push_back(inf);
        int n=nums1.size();
        return rec(nums1,nums2,n-1,true);
    }
};