/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void solve(Node* node, unordered_map<int,vector<Node*>> &mpp, int lvl)
    {
        if(!node)   return;

        if(mpp[lvl].size() != 0)
        {
            auto prev = mpp[lvl].back();
            prev->next = node;
            // node->next = NULL;
        }
        mpp[lvl].push_back(node);

        solve(node->left,mpp,lvl+1);
        solve(node->right,mpp,lvl+1);
    }
public:
    Node* connect(Node* root) {
        unordered_map<int,vector<Node*>> mpp;

        solve(root,mpp,0);
        return root;
    }
};