// #define short int;

class Solution {
    int maxx;
    int dp[2001][4002];
    int solve(int ind, int sum, vector<int> &arr) {
        if (ind >= arr.size() || sum >= maxx) return 0;

        if (dp[ind][sum] != -1) return dp[ind][sum];

        int take = 0, dont = 0;

        if (arr[ind] > sum) {
            int nexInd = lower_bound(arr.begin(), arr.end(), sum + arr[ind]) - arr.begin();
            if (nexInd < arr.size() && arr[nexInd] == sum + arr[ind]) nexInd++;
            take = arr[ind] + solve(nexInd, sum + arr[ind], arr);
        }

        dont = solve(ind + 1, sum, arr);

        return dp[ind][sum] = max(take, dont);
    }

public:
    int maxTotalReward(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        // map<pair<int, int>, int> dp;
        int n = arr.size();
        int j=1;
        for(int i=1; i<n; i++){//Remove the repetitive numbers
            if (arr[i]!=arr[i-1])
                arr[j++]= arr[i];
        }
        n=j;
        arr.resize(n);
        // int dp[2001][4002];
        maxx = 2*arr.back();
        fill(&dp[0][0], &dp[0][0]+2001*maxx, -1);
        return solve(0, 0, arr);
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
