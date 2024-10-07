class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        int n = s.size();
        int cnt = 0;
        for(auto x:s)
        {
            if(stk.empty() || (stk.top() != 'A' && stk.top() != 'C'))
                stk.push(x);
            else
            {
                if(stk.top() == 'A')
                {
                    if(x=='B')
                    {
                        stk.pop();
                        cnt++;
                    }
                    else stk.push(x);
                }
                else if(stk.top() == 'C')
                {
                    if(x=='D')
                    {
                        stk.pop();
                        cnt++;
                    }
                    else stk.push(x);
                }
            }
        }
        return n-(2*cnt);
    }
};