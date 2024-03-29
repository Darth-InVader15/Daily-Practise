class Solution {
    vector<vector<int>> removeLaps(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int prevStrt = arr[0][0] ,prevEnd = arr[0][1], lstIns = -1;
        vector<vector<int>> ans;

        for(int i=1;i<n;i++)
        {
           if(arr[i][0] <= prevEnd)
           {
                prevEnd = max(arr[i][1],prevEnd);
           }
           else
           {
                ans.push_back({prevStrt, prevEnd});
                lstIns = prevStrt;
                prevStrt = arr[i][0];
                prevEnd = arr[i][1];
           }
        }
        if(lstIns != prevStrt)
           {
                ans.push_back({prevStrt,prevEnd});
           }
        return ans;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& inte, vector<int>& newInt) {
        int n = inte.size();
        int s = 0;
        vector<vector<int>> arr;
        // int j = 0;
        for(int i=0;i<n;i++)
        {
            if(inte[i][0] <= newInt[0])
            {
                if(inte[i][0] == newInt[0])
                {
                    if(inte[i][1] < newInt[1])
                    {
                        arr.push_back(inte[i]);
                        arr.push_back(newInt);
                    }
                    else
                    {
                        arr.push_back(newInt);
                        arr.push_back(inte[i]);
                    }
                    // j +=2;
                    continue;
                }
                arr.push_back(inte[i]);
                if(!s && i != n-1 && inte[i+1][0] > newInt[0])
                {
                    arr.push_back(newInt);
                    s=1;
                }
            }
            else if(s == 1) arr.push_back(inte[i]);
            else
            {
                arr.push_back(newInt);
                arr.push_back(inte[i]);
                // j = 2;
                s=1;
            }
        }
        // for(auto x:arr)
        // {
        //     cout<<x[0]<<" "<<x[1]<<endl;
        // }
        if(!s)  arr.push_back(newInt);

        return removeLaps(arr);
    }
};
