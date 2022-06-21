/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int c=0;
        for(int i=0;i<n;i++){
            if(!knows(i,c)){
                c=i;   
            }
            
        }
        if(c>=n)
            return -1;
        for(int i=0;i<n;i++){
            if(!knows(i,c))
                return -1;
        }
        for(int i=0;i<n;i++){
            if(i!=c&&knows(c,i))
                return -1;
        }
   return c; }
};