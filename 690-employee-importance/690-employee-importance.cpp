/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
   int dfs(Employee* i,unordered_map<int,bool> &vis, unordered_map<int,Employee*> &ht){
      vis[i->id]=true;
       
       int v=i->importance;
       for(auto it:i->subordinates){
           if(vis[it]==false)
           v=v+dfs(ht[it],vis,ht);
       }
       return v;
   }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,bool> vis;
        unordered_map<int,Employee*> ht;
        Employee* x;
        for(auto it:employees){
           if(it->id==id){
               x=it;
           }
            ht[it->id]=it;
        }
        return dfs(x,vis,ht);
    }
};