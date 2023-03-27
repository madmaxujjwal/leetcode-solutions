class NumArray {
public:
    int n;
    vector<int> tree;
    NumArray(vector<int>& nums) {
        n=nums.size();
        tree.resize(2*n);int j=n;
        for(int i=0;i<n;i++){
            tree[j]=nums[i];j++;
        }
        for(int i=n-1;i>=0;i--){
            tree[i]=tree[2*i]+tree[2*i+1];
        }
    }
    
    void update(int index, int val) {
        tree[index+n]=val;
        int pos=index+n;
        while(pos>0){
            int l=pos;
            int r=pos;
            if(pos%2==0){
                r++;
            }
            else{
                l--;
            }
            tree[pos/2]=tree[l]+tree[r];
            pos=pos/2;
            
        }
    }
    
    int sumRange(int left, int right) {
        int l=left+n;
        int r=right+n;
        int sum=0;
        
        while(l<=r){
            
            if(l%2==1){
                sum+=tree[l];
                l++;
            }
            if(r%2==0){
                sum+=tree[r];
                r--;
            }
            l=l/2;
            r=r/2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */