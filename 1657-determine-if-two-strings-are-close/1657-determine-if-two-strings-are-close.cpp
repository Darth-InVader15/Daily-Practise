class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;

        map<char,int> mpp1,mpp2,mpp3;
        vector<int>vec1,vec2;
        int s = 0;
        //mpp1 and mpp2 for storing individual freq and mpp3 for storing combine freq
        for(auto x:word1)
        {
            mpp1[x]++;
            mpp3[x]++;
        }
        for(auto x:word2)
        {
            mpp2[x]++;
            mpp3[x]++;
        }
        //if chars in mpp1 or mpp2 !=  mpp3, we know that atleast one of them has diff char
        if(mpp1.size() != mpp3.size() || mpp2.size() != mpp3.size())
            return false;

        //So we have determined that both have same chars
        //using vector for storing the freq 
        for(auto x:mpp1)
        {
            vec1.push_back(x.second);
        }
        for(auto x: mpp2)
        {
            vec2.push_back(x.second);
        }
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());

        //If the chars are same, and the freqs are same, the char can be transformed into 1 another
        //so they are closed strings 
        for(int i=0;i<vec1.size();i++)
        {
            if(vec1[i] != vec2[i])
            s=1;
        }
        if(!s)
        {
            return true;
        }
        

        // for(auto x: word2)
        // {
        //     if(mpp1[x] != mpp2[x])
        //     return false;
        // }

        return false;
    }
};