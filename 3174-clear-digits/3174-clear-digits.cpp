class Solution {
public:
    string clearDigits(string s) {
        stack<char> stk;

        for(auto x:s)
        {
            if(x-'0' >= 0 && x-'0' <=9)
            {
                if(stk.size())  stk.pop();
            }
            else stk.push(x);
        }
        string ans = "";
        while(stk.size())
        {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
 
        
    }
};