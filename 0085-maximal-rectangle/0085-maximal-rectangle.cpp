class Solution {
private:
    int solve(vector<int> &ht)
    {
        int n = ht.size();
        vector<int> nsl(n);
        vector<int> nsr(n);
        
        stack<pair<int,int>> stk;
        for(int i=0;i<n;i++)
        {
            while(!stk.empty())
            {
                if(stk.top().first < ht[i])
                {
                    nsl[i] = stk.top().second;
                    stk.push({ht[i],i});
                    break;
                }
                else
                    stk.pop();
            }
            if(stk.empty())
            {
                nsl[i] = -1;
                stk.push({ht[i],i});
            }
        }
        
        while(stk.size())
            stk.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty())
            {
                if(stk.top().first < ht[i])
                {
                    nsr[i] = stk.top().second;
                    stk.push({ht[i],i});
                    break;
                }
                else
                    stk.pop();
            }
            if(stk.empty())
            {
                nsr[i] = n;
                stk.push({ht[i],i});
            }
        }
        int maxx = -1;
        for(int i=0;i<n;i++)
        {
            int ans = nsr[i]-nsl[i]-1;
            ans*=ht[i];
            maxx = max(maxx,ans);
        }
        return maxx;
    }
public:
    int maximalRectangle(vector<vector<char>>& mtx) {
        int r = mtx.size();
        int c = mtx[0].size();

        vector<int> ht(c,0);
        int ans = -1;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mtx[i][j] != '0')
                ht[j] += 1;
                else
                ht[j] = 0;
            }
            ans = max(ans,solve(ht));
        }
        return ans;
        
    }
};