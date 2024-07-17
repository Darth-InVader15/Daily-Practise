class Solution {
    int solve(int sx,int sy,int ex,int ey, vector<int> &hor, vector<int> &ver)
    {
        if(ex-sx == 1 && ey-sy == 1 )
        {
            return 0;   //already cut
        }

        int takex = 1e9, takey =1e9;

        for(int i=sx+1;i<ex;i++)
        {
            takex = min(takex,hor[i-1]+solve(sx,sy,i,ey,hor,ver)+solve(i,sy,ex,ey,hor,ver));
        }
        for(int i=sy+1;i<ey;i++)
        {
            takey = min(takey,ver[i-1]+solve(sx,sy,ex,i,hor,ver)+solve(sx,i,ex,ey,hor,ver));
        }
        return min(takex,takey);
    }
public:
    int minimumCost(int m, int n, vector<int>& hor, vector<int>& ver) {
        return solve(0,0,m,n,hor,ver);
    }
};