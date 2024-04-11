class Solution {
string ans="";
private:
    string solve(vector<string> s, string pref)
    {
        int end=INT_MAX,curr_end =-1;
        for(int x=1;x<s.size();x++)
        {
            curr_end =-1;
            for(int i=0;i<pref.size();i++)
            {
                if(pref[i] == s[x][i])
                curr_end=i;
                else
                break;
            }
            end = min(end,curr_end);
            if(end == -1)
            {
                ans ="";
                return ans;
            }
        }
        for(int i=0;i<=end;i++)
        {
            ans.push_back(pref[i]);
        }
        return ans;

    }
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.size() == 1)
        return strs[0];
        string pref = strs[0];
        //sort(strs.begin(),strs.end());
        return solve(strs,pref);
        
    }
};