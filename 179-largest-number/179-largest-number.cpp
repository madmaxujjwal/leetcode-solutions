class Solution {
public:
    
    static bool comp(int a,int b){
        string x=to_string(a);
        string y=to_string(b);
        
            return x+y>y+x;
        
        
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        string z="";
        for(int i=0;i<nums.size();i=i+1){
            z=z+to_string(nums[i]);
            if(z=="0")
                z="";
        }
        if(z=="")
       z='0';
        return z;
    }
};