class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int cnt = 0;
        unordered_set<char> vow;
        vow.insert({'a','e','i','o','u'});
        
        for(int i=0;i<n/2;i++)
        {
            if(vow.count(tolower(s[i]))) cnt++;
        }
        for(int i=n/2;i<n;i++)
        {
            if(vow.count(tolower(s[i]))) cnt--;
        }
        return (cnt==0);
    }
};