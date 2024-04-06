class Solution {
// private:
//     int solve(vector<int> prices)
//     {
//         //7 1 5 3 6 4
        
//     }
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int lowCP = INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            if(lowCP > prices[i])
            {
                lowCP = prices[i];
            }
            if(prices[i] - lowCP > ans)
            ans = prices[i] - lowCP;
        }
        return ans;
        
    }
};