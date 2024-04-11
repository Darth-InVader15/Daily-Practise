class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        if(k == num.size()) return "0";

        for(auto x: num)
        {
    
            while(!stk.empty() && k && stk.top() > x)
            {
                stk.pop();
                k--;
            }
            stk.push(x);
        }
        if(k)
        {
            while(k--)  stk.pop();
        }
        string ans = "";

        while(stk.size())
        {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());

        if(ans[0] == '0')
        {
            int i = 0;
            while(ans[i] == '0')    i++;
            
            ans.erase(0,i);

            if(ans.size() == 0) ans = "0";
        }
        return ans;
        
    }
};