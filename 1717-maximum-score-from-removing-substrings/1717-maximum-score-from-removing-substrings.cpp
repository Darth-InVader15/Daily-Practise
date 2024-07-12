class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> stk;
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(stk.empty()) stk.push(s[i]); //either empty stack or not ab forming elements
            else
            {
                string temp = "";
                temp.push_back(stk.top());
                temp.push_back(s[i]);

                if(x>=y) // remove all "ab"
                {
                    if(temp == "ab")
                    {
                        ans += x;
                        stk.pop();
                        continue;
                    }
                }
                else
                {
                    if(temp == "ba")
                    {
                        stk.pop();
                        ans += y;
                        continue;
                    }
                }
                stk.push(s[i]);
            }
        }
        //we have removed the majority string
            string str = "";
            while(stk.size())
            {
                str.push_back(stk.top());
                stk.pop();
            }
            reverse(str.begin(),str.end());
        
        for(int i=0;i<str.size();i++)
        {
            if(stk.empty()) stk.push(str[i]); //either empty stack or not ab forming elements
            else
            {
                string temp = "";
                temp.push_back(stk.top());
                temp.push_back(str[i]);

                if(x>=y) // remove all "ab"
                {
                    if(temp == "ba")
                    {
                        ans += y;
                        stk.pop();
                        continue;
                    }
                }
                else
                {
                    if(temp == "ab")
                    {
                        stk.pop();
                        ans += x;
                        continue;
                    }
                }
                stk.push(str[i]);
            }
        }
        return ans;

    }
};