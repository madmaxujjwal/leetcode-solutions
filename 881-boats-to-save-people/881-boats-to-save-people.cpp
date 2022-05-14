class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int i=0;int j=n-1;
        int c=0;
        while(i<=j){
            if(i==j){
                if(people[i]<=limit)
                    c++;
                break;
            }
            if((people[i]+people[j])<=limit){
                c++;
                i++;
                j--;
            }
            else
            {
                if(people[j]<=limit)
                    c++;
                j--;
            }
        }
        return c;
    }
};