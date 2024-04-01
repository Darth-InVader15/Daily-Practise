class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int cnt = 0;

        int strt = n-1;

        while(s[strt] == ' ')   strt--;
        for(int i=strt;i>=0;i--)
        {
            if(s[i] == ' ') break;
            cnt++;
        }
        return cnt;
    }
};