class Solution {
    bool static cstm(vector<int> &a, vector<int> &b)
    {
        if(a[0]<b[0])   return 1;
        else if(a[0] == b[0])   return a[1] > b[1];
        else return 0;
    }
public:
    int countDays(int days, vector<vector<int>>& meets) {
        unordered_map<int,int> mpp;

        // for(int i=0;i<=days;i++)    mpp[i] = 0;
        sort(meets.begin(),meets.end(),cstm);
        vector<vector<int>> arr;
        arr.push_back(meets[0]);

        for(auto x:meets)   cout<<"--"<<x[0]<<" "<<x[1]<<endl;

        for(int i=1;i<meets.size();i++)
        {
            int currStrt = meets[i][0];
            int prevEnd = arr.back()[1];

            if(currStrt <= prevEnd)
            {
                arr.back()[1] = max(meets[i][1],arr.back()[1]);
            }
            else    arr.push_back(meets[i]);
        }
        int cnt =0;
        int n = arr.size();
        for(auto x:arr)
        {
            cout<<x[0]<<" "<<x[1]<<endl;
        }
        for(int i=1;i<n;i++)
        {
            cnt += (arr[i][0] - (1+arr[i-1][1]));
        }
        cnt += (days - (1+arr[n-1][1]));
        cnt += (arr[0][0] - 1);
        return cnt+1;

    }
};