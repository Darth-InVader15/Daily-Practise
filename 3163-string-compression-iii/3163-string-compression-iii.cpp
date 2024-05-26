class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        char ch = word[0];
        int cnt = 1;

        if(word.size() == 1)
        {
            ans += "1";
            ans += word[0];
            return ans;
        }

        for(int i=1;i<word.size();i++)
        {
            if(word[i] == ch)
            {
                cnt++;
                if(cnt > 9)
                {
                    ans+= "9";
                    ans+=ch;
                    cnt=1;
                    continue;
                }
                
            }
            else
            {
                ans += to_string(cnt);
                ans += ch;
                cnt = 1;
                ch = word[i];
            }
            if(i== word.size()-1)
                {
                    ans += to_string(cnt);
                    ans += ch;
                }
        }
        return ans;
    }
};