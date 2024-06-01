class Solution {
public:
    vector<int> queryResults(int lt, vector<vector<int>>& q) {
        unordered_map<int,int> mpp;
        // unordered_set<int> stt;
        vector<int> ans(q.size());
        unordered_map<int,int> arr;
        int cnt = 0;

        for(int i=0;i<q.size();i++)
        {
            int ind = q[i][0];
            int col = q[i][1];

            if(arr[ind] == 0)
            {
                // arr[ind] = col;
                if(mpp.find(col) == mpp.end() || mpp[col] == 0) //agar pehele se yeh colour nhi tha 
                    cnt++;
                
            }
            else
            {
                mpp[arr[ind]]--;
                // cout<<i<<" "<<ind<<" "<<mpp[arr[ind]]<<endl;
                if(mpp[arr[ind]] == 0)
                {
                    // stt.erase(arr[ind]);
                    cnt--;
                    // cout<<stt.size()<<"--"<<endl;
                }

                if(mpp.find(col) == mpp.end() || mpp[col] == 0) //agar pehele se yeh colour nhi tha 
                    cnt++;
                    // stt.insert(col);
            }
            // cout<<stt.size()<<endl;
            mpp[col]++;
            arr[ind] = col;
            ans[i] = cnt;
        }
        return ans;
    }
};