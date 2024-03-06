class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& arr) {
        vector<int> arry(3,0), arrx(3,0);
        int n = arr.size();
        int m = n;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i == j && i <= n/2 )   arry[arr[i][j]]++;
                else if(j+i == m-1 && i <= n/2 && j>n/2)  arry[arr[i][j]]++;
                else if(j == m/2 && i>= n/2)    arry[arr[i][j]]++;
                
                else arrx[arr[i][j]]++;
            }   
        }
        int toty = (n/2) + (n/2) + (n/2) + 1;
        int totx = (n*n) - toty;
        
        int maxx = 0, maxi = 0, maxm = 0, maxy = -1, maxi2 = 0, max2 = 0;
        priority_queue<pair<int,int>> pq1,pq2;
        for(int i = 0; i<3 ;i++)
        {
            pq1.push({arry[i],i});
            pq2.push({arrx[i],i});
        }
        // cout<<pq2.top().first<<" "<<pq1.top().first<<endl;
        if(pq1.top().second == pq2.top().second)
        {
            maxx = pq2.top().first;
            maxm = pq1.top().first;
            pq2.pop();
            pq1.pop();
            
            int ans = min(((totx-pq2.top().first)+(toty - maxm)), totx + toty - (maxx + pq1.top().first));
            return ans;

        }
        else
        {
            maxx = pq2.top().first;
            maxm = pq1.top().first;
        }
        // cout<<maxx<<" "<<maxi<<" "<<maxm<<" "<<maxy<<endl;
        int ans = (totx - maxx) + (toty - maxm);
        return ans;
        
    }
};