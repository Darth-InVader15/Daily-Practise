class Solution {
    int dfs(vector<vector<int>> &arr)
    {
        int n = arr.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({arr[0][0],{0,0}});
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        vector<vector<int>> vis(n,vector<int>(n,0));
        while(!pq.empty())  
        {
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            // cout<<time<<" "<<x<<" "<<y<<endl;

            if(x == n-1 && y == n-1)    return time;
            if(vis[x][y])   continue;
            vis[x][y] = 1;

            for(int i=0;i<4;i++)
            {
                int tx = x + dx[i];
                int ty = y + dy[i];

                if(!isVal(tx,ty,n))   continue;
                if(arr[tx][ty] <= time && !vis[tx][ty]) pq.push({time,{tx,ty}}); //can travel infinite dist in 0 time
                else if(arr[tx][ty] > time)
                {
                    // if(vis[x][y] >= time+1)  continue; //already is at better time
                    pq.push({arr[tx][ty],{tx,ty}}); // we wait for the time to rise
                }
            }
        }
        return -1;
    }
    int isVal(int x,int y,int n)
    {
        // int n =arr.size();
        if(x<0 || y<0 || x>= n || y>=n) return 0;
        return 1;
    }
public:
    int swimInWater(vector<vector<int>>& arr) {
        return dfs(arr);
    }
};