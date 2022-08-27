class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long int  n=nums.size();
        sort(nums.begin(),nums.end());
        map<long long int ,long long int > ht;
        long long int ans=0;
        for(int i=0;i<n;i++){
            ht[nums[i]]++;
        }
        long long int  p=0;long long int  next,v;
        for(auto it:ht){
            if(k==0){
                break;
            }
            long long int next=it.first-1;
            long long int  v=k;
            k=k-(next-p);
            if(k<=0){
                next=p+v;
                ans=ans+next*(next+1)/2-p*(p+1)/2;
                break;
            }
            ans=ans+next*(next+1)/2-p*(p+1)/2;
            p=it.first;
            
        }        if(k>0){
                next=p+k;
                ans=ans+next*(next+1)/2-p*(p+1)/2;}
        return ans;
    }
};