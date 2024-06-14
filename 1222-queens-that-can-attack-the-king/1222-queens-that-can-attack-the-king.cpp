class Solution {
    void plus(int tx, int ty, set<vector<int>> &q, vector<vector<int>> &ans)
    {
        int nx,ny,px,py;
        int n =0, p=0;
        for(int i=0;i<8;i++)
        {
            nx = tx+i;
            px = tx-i;
            if(nx>7)    n=1;
            if(px<0)    p=1;

            // cout<<nx<<" "<<ny<<" "<<px<<endl;
            
            if(!n && q.count({nx,ty}))
            {
                ans.push_back({nx,ty});
                n=1;
            }
            if(!p && q.count({px,ty}))
            {
                ans.push_back({px,ty});
                p=1;
            }
        }
        n=0, p =0;
        for(int i=0;i<8;i++)
        {
            ny = ty+i;
            py = ty-i;
            if(ny > 7)  n=1;
            if(py < 0)  p=1;

            // cout<<ny<<" "<<tx<<"- "<<py<<endl;
            if(!n && q.count({tx,ny}))
            {
                ans.push_back({tx,ny});
                n=1;
            }
            if(!p && q.count({tx,py}))
            {
                ans.push_back({tx,py});
                p=1;
            }
        }  
    }
    void cross(int tx, int ty, set<vector<int>> &stt, vector<vector<int>> &ans)
    {
        int nx,ny,px,py;
        int n=0, p=0;
        for(int i=0;i<8;i++)
        {
            nx = tx+i, ny = ty+i;
            px = tx-i, py = ty-i;

            // cout<<nx<<" "<<ny<<endl;
            if(n==0 && nx < 8 && ny < 8 && stt.count({nx,ny}))
            {
                // cout<<nx<<" "<<ny<<endl;
                ans.push_back({nx,ny});
                n=1;
            }
            if(p==0 && px>=0 && py >= 0 && stt.count({px,py}))
            {
                ans.push_back({px,py});
                p=1;
            }
        }
        n=0, p=0;
        for(int i=0;i<8;i++)
        {
            nx = tx+i, ny = ty-i;
            px = tx-i, py = ty+i;
            if(n==0 && nx < 8 && ny < 8 && stt.count({nx,ny}))
            {
                ans.push_back({nx,ny});
                n=1;
            }
            if(p==0 &&px>=0 && py >= 0 && stt.count({px,py}))
            {
                ans.push_back({px,py});
                p=1;
            }
        }
    }
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        //instead of manipulating with all the queens
        //focus on the king\U0001f451

        int tx=king[0], ty=king[1];
        set<vector<int>> q(queens.begin(),queens.end());
        vector<vector<int>> ans;

        plus(tx,ty,q,ans);
        cross(tx,ty,q,ans);

        return ans;

           
    }
};