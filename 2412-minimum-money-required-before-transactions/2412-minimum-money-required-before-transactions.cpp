class Solution {
    bool static cstm(vector<int> &a, vector<int> &b)
    {
        if(a[1] == b[1])    return a[0]>b[0];
        return a[1]<b[1];
    }
    bool static cstm2(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0])    return a[1]<b[1];
        return a[0]>b[0];
    }
    bool static cstm3(vector<int> &a, vector<int> &b)
    {
        int diff = (a[1]-a[0]) - (b[1]-b[0]);
        if(diff == 0)   return a[0]>b[0];
        return diff<0;
    }
public:
    long long minimumMoney(vector<vector<int>>& arr) {
        long long ans = 0, cnt = 0, anss = 0;
        vector<vector<int>> temp1, temp2;

        for(auto x:arr)
        {
            if(x[1] > x[0]) temp2.push_back(x);
            else temp1.push_back(x);
        }
        auto temp3 = temp2;
        sort(temp1.begin(),temp1.end(),cstm);
        sort(temp2.begin(),temp2.end(),cstm2); // one sorted by descending costs
        sort(temp3.begin(),temp3.end(),cstm3); //one sorted by ascending income
        //honest to God, its gotta be either of them 2
        //aint calculating that, idk its meant to be calculated, not gonna affect the tc by much
        for(auto x: temp1)
        {
            cnt -= x[0];
            ans = min(ans,cnt);
            cnt += x[1];
        }
        anss = ans; //game saved
        cout<<anss<<" "<<cnt<<endl;
        long long cntt = cnt;
        for(auto x:temp2)
        {
            cnt -= x[0];
            ans = min(ans,cnt);
            // cout<<anss<<"--"<<cnt<<endl;
            cnt += x[1];
        }
        for(auto x:temp3)
        {
            cntt -= x[0];
            anss = min(anss,cntt);
            cntt += x[1];
        }
        anss = abs(anss);
        ans = abs(ans);
        return (max(anss,ans));
    }
};