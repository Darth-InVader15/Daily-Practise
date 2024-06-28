class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        //an observation
        //1->the node with the most links have the highest number
        //2->Nodes connected to number with high values have high values(Ex 2)
        //2nd point is not needed, the ans is basically assigned num * num of links
        // so we just need to assign the max num to the one with the max links

        vector<int> arr(n,0);
        //  arr;

        for(auto x:roads)
        {
            arr[x[0]]++;
            arr[x[1]]++;
        }
        sort(arr.begin(),arr.end(),greater<int>());

        long long ans = 0;
        int cnt = n;

        for(auto x:arr)
        {
            ans += (1ll*cnt*x);
            cnt--;
        }
        return ans;



    }
};