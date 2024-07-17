class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        for(int i=0;i<n-1;i++)
        {
            int a = s[i]-'0', b = s[i+1]-'0';

            if(a%2 == b%2)
            {
                if(b<a)
                {
                    s[i] = b+'0';
                    s[i+1] = a + '0';
                    break;
                }
            }
        }
        return s;
    }
};