class Solution {
    int mod = 1e9 + 7;
    int solve(int ind,int prev, string &str, unordered_set<int> &taken, vector<int> &anss)
    {
        if(str.size() < ind)
        {
            // for(auto x:anss)    cout<<x<<" ";
            // cout<<endl;
            return 1;
        }

        int ans = 0;
        for(int i=0;i<=str.size();i++)
        {
            if(taken.count(i))  continue;
            if(prev != -1) //checking if curr selection is valid for prev str[ind]
            {
                if(str[ind-1] == 'D'){
                    if(prev < i )  continue;
                }
                else    if(prev > i)    continue;
            }
            taken.insert(i);
            // anss.push_back(i);
            ans = (ans+solve(ind+1,i,str,taken,anss))%mod;
            // anss.pop_back();
            taken.erase(i);
        }
        // cout<<ind<<" "<<prev<<" "<<ans<<endl;
        return ans;
    }
public:
    int numPermsDISequence(string s) {
        unordered_set<int> taken;
        vector<int> anss;
        return solve(0,-1,s,taken,anss);//,anss);
    }
};