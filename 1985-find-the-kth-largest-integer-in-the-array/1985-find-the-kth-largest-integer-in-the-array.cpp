class Solution {
public:
    struct cmp {
    bool operator() (string a,string b){
        if(a.size()==b.size())
        return (a>b);
        return (a.size()>b.size());
    }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,cmp> minh;
        int n=nums.size();
        for(int i=0;i<n;i++){
            minh.push((nums[i]));
            if(minh.size()>k){
                minh.pop();
            }
        }
        return (minh.top());
    }
};