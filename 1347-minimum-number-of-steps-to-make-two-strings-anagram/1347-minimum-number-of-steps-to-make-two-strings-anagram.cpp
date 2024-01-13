class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int> mpp;
        
        for(auto x: s)
        {
            mpp[x]++;
        }
        int cnt = 0;
        
        for(auto x: t)
        {
            if(mpp[x] == 0)   cnt++;
            else mpp[x]--;
        }
        return cnt;
    }
};