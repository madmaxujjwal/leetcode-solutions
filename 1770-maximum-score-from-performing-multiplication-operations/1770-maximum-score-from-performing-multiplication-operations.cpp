class Solution {
public:
    int ht[1001][1001];int n;
    int m;
    int rec(vector<int> &a, vector<int> &b,int i,int c){
        
        if(c==m){
            return 0;
        }
         if(ht[i][c]!=-1)
            return ht[i][c];
      
         int j=n-(c-i+1);
        
       
      int l= a[i]*b[c]+rec(a,b,i+1,c+1);
        int r=a[j]*b[c]+rec(a,b,i,c+1);
        
        return ht[i][c]=max(l,r);
        
    }
    
    
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
         n=nums.size();
         m=multipliers.size();
      memset(ht,-1,sizeof(ht));
        return rec(nums,multipliers,0,0);
    }
};