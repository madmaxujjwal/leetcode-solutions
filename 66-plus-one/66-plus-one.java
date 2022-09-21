class Solution {
    public int[] plusOne(int[] digits) {
        int n=digits.length;int val;int carry=1;
        for(int i=n-1;i>=0;i--){
             val=digits[i];
            if(val+carry>9){
                digits[i]=0;
                carry=1;
            }
            else{
                digits[i]=val+carry;
                carry=0;
                
            }
            
            
        }
        if(carry==0){
            return digits;
        }
        else{
            int res[]=new int[n+1];
            res[0]=1;
            for(int i=1;i<=n;i++){
                res[i]=digits[i-1];
            }
            return res;
        }
    }
}