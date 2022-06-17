class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                ans[i]=n;
                st.push({nums[i],i});
                continue;
            }
            while(st.size()!=0&&st.top().first>=nums[i]){
                st.pop();
            }
            if(st.size()==0){
                ans[i]=n;
            }
            else{
                ans[i]=st.top().second;
            }
             st.push({nums[i],i});
        }
        int answer=0;
        for(int i=0;i<n;i++){
            answer+=ans[i]-i;
        }
        return answer;
    }
};