/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    vector<vector<int>> levelOrder(Node* root) {
        if(root==nullptr)
            return {};
        vector<vector<int>> ans;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(q.size()>0){
            Node* temp=q.front().first;
            int i=q.front().second;
            if(ans.size()<(i+1)){
                ans.push_back({temp->val});
            }
            else
            ans[i].push_back(temp->val);
            q.pop();
            for(auto it:temp->children){
                q.push({it,i+1});
            }
        }
        return ans;
    }
};