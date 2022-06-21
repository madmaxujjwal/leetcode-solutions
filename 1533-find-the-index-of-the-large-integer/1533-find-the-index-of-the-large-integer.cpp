/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int n=reader.length();
        int i=0;
        int j=n-1;
        while(i<j){
            int m=(i+j)/2;
            if((j-i+1)%2==0){
                int a=reader.compareSub(i,m,m+1,j);
                if(a==1){
                    j=m;
                }else{
                    i=m+1;
                }
            }else{
                int a=reader.compareSub(i,m,m,j);
                if(a==1){
                    j=m;
                }
                else if(a==0){
                    return m;
                }
                else{
                    i=m;
                }
            }
        }
        return i;
    }
};