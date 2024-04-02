class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, unordered_set<char>> mpp;
        unordered_map<char, unordered_set<char>> tpp;
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]].insert(t[i]);
            tpp[t[i]].insert(s[i]);
        }
        for(int i=0;i<s.size();i++)
        {
            if(mpp[s[i]].size() > 1)
            return 0;
            if(tpp[t[i]].size() > 1)
            return 0;
        }
        // for(auto x:tpp)
        // {
            
        // }
        return 1;


        
    }
};