class DisjointSet
{
    vector<int>par;
    int distinctComp;
    public:
    DisjointSet(int n){
        distinctComp = n;
        par.resize(n+1);
        // sizee.resize(n+1,1);
        for(int i=0;i<=n;i++)   par[i] = i;
    }
    int findUPar(int node){
        if(par[node] == node) return node;
        return par[node] = findUPar(par[node]);
    }
    bool connect(int u,int v){
        if(findUPar(u) == findUPar(v))
        {
            return false;
        }
        par[findUPar(u)] = findUPar(v);
        distinctComp--;
        return 1;
    }
    bool united() {
        return distinctComp == 1;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        //we have to divide this graph into 2 MSTs so that 
        //both Alice and Bob can travel it
        //My intuition
        //we start building the connections, first by the mutual edge then their personal edge
        //after each edge, we check whether all nodes for Bob/Alice are connected or not
        //We stop appropriately for either
        
        sort(edges.begin(),edges.end(),greater<vector<int>>());
        DisjointSet Bob(n), Alice(n);
        int edgesMade = 0;
        for(auto x:edges)
        {
            int cat = x[0], u = x[1], v = x[2];
            if(cat == 3) //both alice and bob
            {
                if(Bob.connect(u,v) || Alice.connect(u,v))  edgesMade++;
            }
            else if(cat == 2)
            {
                if(Bob.connect(u,v))    edgesMade++;
            }
            else if(cat == 1) edgesMade += (Alice.connect(u,v) == 1);
        }
        cout<<edgesMade<<endl;
        if(Bob.united() && Alice.united()) return edges.size()-edgesMade;
        return -1;

    }
};