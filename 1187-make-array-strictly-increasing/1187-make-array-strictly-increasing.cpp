class Solution {
public:
    vector<int> a;
    vector<int> b;
    map<pair<int,int>,int> dp;
    int rec(int i,int j){
        if(j==-1){
            return 10000000;
        }
        if(i==0){
            return 0;
        }
        if(dp.find({i,j})!=dp.end())
            return dp[{i,j}];
        if(a[i-1]<j){
            int ind=lower_bound(b.begin(),b.end(),j)-b.begin();
            int ele=-1;
            if(ind!=0){
                ele=b[ind-1];
            }
            return dp[{i,j}]= min(rec(i-1,a[i-1]),1+rec(i-1,ele));
        }
        else{
            int ind=lower_bound(b.begin(),b.end(),j)-b.begin();
            int ele=-1;
            if(ind!=0){
                ele=b[ind-1];
            }
            return dp[{i,j}]=1+rec(i-1,ele);
        }
        
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        a=arr1;
        b=arr2;
        sort(b.begin(),b.end());
        int ans= rec(n,INT_MAX);
        if(ans>=10000000){
            return -1;
        }
        return ans;
    }
};