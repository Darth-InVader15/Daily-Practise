class Solution {
    static bool cstm(pair<int,char> &a, pair<int,char> &b)
    {
        return a.first>b.first;
    }
public:
    string frequencySort(string s) {
        vector<pair<int,char>> arr(62);

        for(auto x:s)
        {
            // for digits
            if(x >= '0' && x <='9')
            {
                arr[x-'0'+52].first++;
                arr[x-'0'+52].second = x;
                continue;
            }

            // for caps 65...
            if(x < 'a'){
                arr[x-'A' + 26].first++;
                arr[x-'A' + 26].second = x;
                continue;
            }
            
            //for small 97...
            arr[x-'a'].first++;
            arr[x-'a'].second = x;
        }
        sort(arr.begin(),arr.end(),cstm);
        string ans = "";

        for(auto x:arr)
        {
            if(x.first == 0)    continue;
            
            // cout<<x.first<<" "<<x.second<<endl;

            while(x.first--)
            {
                ans+= x.second;
            }
        }
        return ans;

        
        
    }
};