class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,stack<int>> mpp;

        for(int i=0;i<s.size();i++)
        {
            if(mpp[s[i]].size() == 2) //this is the third ele
            {
                int t = mpp[s[i]].top();
                mpp[s[i]].pop();    // take out the middle ele
                mpp[s[i]].pop();    //delete the first ele
                mpp[s[i]].push(t);  //reinsert the second ele
            }
            else mpp[s[i]].push(i);
        }
        int ans = 0;
        for(char ch='a';ch<='z';ch++)
        {
            ans += mpp[ch].size();
        }
        return ans;
    }
};