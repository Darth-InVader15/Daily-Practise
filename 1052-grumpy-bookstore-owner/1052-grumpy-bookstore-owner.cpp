class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& gru, int mins) {
        int alt = 0, art = mins-1;
        int cnt = 0, cntt = 0;
        int lt = 0, rt = 0;

        while(rt<cust.size())
        {
            // cntt = 0;
            while(rt-lt<mins)
            {
                if(gru[rt]) cntt += cust[rt];
                rt++;
            }
            if(rt-lt == mins)
            {
                if(cntt > cnt)
                {
                    alt = lt, art = rt-1;
                    cnt = cntt;
                }
                if(gru[lt]) cntt -= cust[lt];
                lt++;
            }
        }
        // cout<<alt<<" "<<art<<endl;
        int ans = 0;

        for(int i=0;i<cust.size();i++)
        {
            if(gru[i] == 0 || (i>=alt && i <= art))
                ans += cust[i];
        }
        return ans;
    }
};