class Solution {
    string ans;
    int m;

    string newStr(string &str)
    {
        char ch=str[0];
        int cnt = 1;
        string s = "";

        for(int i=1;i<str.size();i++)
        {
            if(str[i] == ch)    cnt++;
            else
            {
                s += to_string(cnt);
                s += ch;
                cnt = 1;
                ch = str[i];
            }

            if(i==str.size()-1)
            {
                s += to_string(cnt);
                s += ch;   
            }
        }
        return s;
    }
    void solve(int ind, string str)
    {
        if(ind == m)
        {
            ans = str;
            return;
        }

        string neStr = ind == 1 ? "11" : newStr(str);
        cout<<neStr<<endl;
        solve(ind+1,neStr);

    }
public:
    string countAndSay(int n) 
    {
        m =n;
        solve(1,"1");
        return ans;
    }
};