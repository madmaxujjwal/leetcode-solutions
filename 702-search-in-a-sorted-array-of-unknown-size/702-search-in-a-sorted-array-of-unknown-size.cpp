/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int i=0;
        int j=9999;
        while(i<=j){
            int m=(i+j)/2;
            int v=reader.get(m);
            if(v==INT_MAX){
                j=m-1;
                continue;
            }
            if(v==target){
                return m;
            }
            else if(v>target){
                j=m-1;
            }
            else{
                i=m+1;
            }
        }
        return -1;
    }
};