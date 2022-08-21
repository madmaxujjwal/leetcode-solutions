class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        int n=jobs.size();
        sort(jobs.begin(),jobs.end());
        sort(workers.begin(),workers.end());
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
           if(ans< ceil((double)jobs[i]/(double)workers[i]))
               ans=ceil((double)jobs[i]/(double)workers[i]);
        }
        return ans;
    }
};