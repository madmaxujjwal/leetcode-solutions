class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n=nums.size();
        priority_queue<double> maxh;double s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            double z=nums[i];
            maxh.push(z);
        }s=s/2;
        double sum=0;int c=0;
        while(sum<s){
            double z=maxh.top();
            z=z/2;
            sum+=z;
            maxh.pop();
            maxh.push(z);
            c++;
            
            
        }
        return c;
    }
};