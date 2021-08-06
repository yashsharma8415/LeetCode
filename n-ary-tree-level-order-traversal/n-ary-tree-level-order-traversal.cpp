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
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<int> v[1005];
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            auto ele = q.front();
            q.pop();
            
            if(ele.first == NULL)
                break;
            
            v[ele.second].push_back(ele.first->val);
            
            for(auto node : ele.first->children)
                q.push({node, ele.second + 1});
        }
        
        vector<vector<int>> ans;
        
        for(int i=0; i<1005; ++i)
        {
            if(v[i].empty())
                break;
            
            ans.push_back(v[i]);
        }
        
        return ans;
    }
};