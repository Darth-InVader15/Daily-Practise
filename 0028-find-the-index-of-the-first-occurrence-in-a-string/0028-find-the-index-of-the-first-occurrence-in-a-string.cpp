class Solution {
    vector<int> preprocess(string &s)
    {
        vector<int> kmp(s.size());
        int i = 1, m = 0;
        kmp[0] = 0;

        while(i<s.size())
        {
            if(s[i] == s[m])
            {
                kmp[i++] = ++m;
            }
            else if(m>0)    m = kmp[m-1];
            else kmp[i++] = 0;
        }
        return kmp;

    }
public:
    int strStr(string haystack, string needle) {
        vector<int> ind(26,0);
        // vector<pair<char,int>> dict(needle.size()+1);
        int n = haystack.size(), m = needle.size();

        vector<int> kmp = preprocess(needle);

        // for(int i=0;i<needle.size();i++)
        // {
        //     dict[i+1] = {needle[i],ind[needle[i]-'a']}; //we saving the earlier occurence
        //     if(ind[needle[i]-'a'] == 0) ind[needle[i]-'a'] = i+1;
        // }
        int j = 0, i =0;
        while(i<n && j<m)
        {
            while(i<n && j<m && haystack[i] == needle[j])
            {
                i++;
                j++;
                if(j == m)
                {
                    return i-m;
                } //match found
                if(i == n)  return -1; //string over
            }
            if(haystack[i] != needle[j])
            {
                if(j == 0)
                {
                    i++;
                }
                else
                {
                    j = kmp[j-1]; //jo pichla match kara tha
                    
                }
                continue;
            }
        }
        return -1;
    }
};