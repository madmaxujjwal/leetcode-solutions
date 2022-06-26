/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int dfs(NestedInteger i,int d,int &m,int &n,int &su){
        if(i.isInteger()){
            n++;
            m=max(m,d);
            su=su+i.getInteger();
            return (i.getInteger())*d;
        }
        vector<NestedInteger> z=i.getList();
        int s=0;
        for(auto it:z){
            s+=dfs(it,d+1,m,n,su);
        }
        return s;
    }
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int n=0;
        int m=0;
        int sum=0;int su=0;
        for(auto it:nestedList){
            sum+=dfs(it,1,m,n,su);
        }
        return su*(m+1)-sum;
    }
};