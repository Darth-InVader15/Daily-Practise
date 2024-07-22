class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& ht) {
        int n = ht.size();
        vector<pair<int,int>> arr(n);
        
        for(int i=0;i<n;i++)    arr[i] = {ht[i],i};
        sort(arr.begin(),arr.end(),greater<pair<int,int>>());

        vector<string> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i] = names[arr[i].second];
        }
        return ans;
    }
};