class Solution {
    //wrote a similar code using iterative Djikstra, got MLE
public:
    //Building the Graph
    void dfs(TreeNode *root , unordered_map<int , vector<pair<int , char>>> &g){
        if(!root)
            return;
        if(root->left){
            g[root->val].push_back({root->left->val , 'L'});
            g[root->left->val].push_back({root->val , 'U'});
        }
        if(root->right){
             g[root->val].push_back({root->right->val , 'R'});
             g[root->right->val].push_back({root->val , 'U'});
        }
        dfs(root->left , g);
        dfs(root->right , g);
        return;
    }
    //Finding Shortest Path
    string bfs(unordered_map<int , vector<pair<int , char>>> &g , int src , int end){
        vector<int> dis(g.size() + 1 , (int)1e9);
        unordered_map<int , pair<int , char>> path;
        dis[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &[adj_node , dir] : g[node]){
                if(dis[adj_node] > dis[node] + 1){
                    dis[adj_node] = dis[node] + 1;
                    path[adj_node] = {node , dir};
                    q.push(adj_node);
                }
            }
        }
        string s{""};
        while(1){
            if(end == src){
                break;
            }
            int x = path[end].first;
            s += path[end].second;
            end = x;
        }
        reverse(s.begin() , s.end());
        return s;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<int , vector<pair<int , char>>> g;
        dfs(root , g);        
        return bfs(g , startValue , destValue);
    }
};