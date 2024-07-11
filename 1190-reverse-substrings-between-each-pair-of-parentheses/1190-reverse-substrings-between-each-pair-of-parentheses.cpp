class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;

        for(auto x: s)
        {
            if(x != ')')    stk.push(x);
            else
            {
                string temp = "";
                while(stk.top() != '(')
                {
                    temp += stk.top();
                    stk.pop();
                }
                stk.pop();
                for(auto t:temp)    stk.push(t);
            }
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