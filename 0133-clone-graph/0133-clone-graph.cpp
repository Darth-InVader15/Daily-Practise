/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
unordered_map<int,Node*> vis;
private:
    Node* solve(Node* root)
    {
        if(!root)   return root;
        Node* temp = new Node(root->val); //creating a new node with same val
        auto arr = root->neighbors;
        // temp->neighbors = arr;

        if(vis.find(temp->val) != vis.end())  return vis[temp->val];
        vis[temp->val] = temp;

        for(auto x:arr)
        {
            temp->neighbors.push_back(solve(x)); //solve(x) returns the duplicated node
           
        }
        cout<<temp->val<<" ";
        for(auto x: temp->neighbors)    cout<<x->val<<" ";
        cout<<endl;
        return temp; 
    }
public:
    Node* cloneGraph(Node* node) {
        return solve(node);
    }
};