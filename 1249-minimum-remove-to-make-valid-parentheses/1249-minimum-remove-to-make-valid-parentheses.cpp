class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt0 = 0;
        string ans = "";

        for(auto x: s)
        {
            if(x == '(')    cnt0++;
            else if(x == ')')
            {
                if(cnt0)   cnt0--;
                else continue;
            }
            ans += x;
        }
        // cout<<cnt0<<"--\n";

        if(!cnt0)   return ans;
        string anss = "";

        for(auto x:ans)
        {
            // if(!cnt0)   break;
            if(cnt0 && x == '(')
            {
                cnt0--;
                // if(!cnt0)   break;
                continue;
                
            }
            anss += x;
        }
        return anss;
    }
};