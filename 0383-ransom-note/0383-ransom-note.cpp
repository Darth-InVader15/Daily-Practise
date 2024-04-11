class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mpp;

        for(auto x:magazine)    mpp[x]++;

        for(auto x:ransomNote)
        {
            if(mpp[x] <= 0) return 0;
            mpp[x]--;
        }
        return 1;
        
    }
};