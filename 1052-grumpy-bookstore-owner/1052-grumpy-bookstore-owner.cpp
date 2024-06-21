class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& gru, int mins) {
        int alt = 0, art = mins-1;
        int cnt = 0;
        int lt = 0, rt = 0;

        while(lt<cust.size()-(mins-1))
        {
            int cntt = 0;
            for(int i=0;i<mins;i++)
            {
                if(gru[lt+i])  cntt += cust[lt+i];
            }
            if(cntt > cnt )
            {
                alt = lt, art = lt+mins-1;
                cnt = cntt;
            }
            lt++;
        }
        cout<<alt<<" "<<art<<endl;
        int ans = 0;

        for(int i=0;i<cust.size();i++)
        {
            if(gru[i] == 0 || (i>=alt && i <= art))
                ans += cust[i];
        }
        return ans;
    }
};