class Solution {
public:
    // int ans = 0;
    bool isPos(vector<int> &fre, vector<int> &freq)
    {
        for(int i=0;i<26;i++)   if(fre[i] > freq[i])    return 0;
        return 1;
    }
    int solve(int ind, vector<string> &words, vector<int> &freq, vector<int> &scores, map<pair<int,vector<int>>, int> &mpp)
    {
        if(ind == words.size()) return 0;

        if(mpp.count({ind,freq}))   return mpp[{ind,freq}];
        int anss = 0;
        auto word = words[ind];
        vector<int> fre(26,0);

        for(auto x:word)
        {
            fre[x-'a']++;
            anss += scores[x-'a'];
        }
        int take = 0, dont = 0;
        if(isPos(fre,freq))
        {
            for(int i=0;i<26;i++)   freq[i] -= fre[i];
            take = anss + solve(ind+1,words,freq,scores,mpp);
            for(int i=0;i<26;i++)   freq[i] += fre[i];
        }
        dont = solve(ind+1,words,freq,scores,mpp);

        return mpp[{ind,freq}] = max(take,dont);

    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> arr(26,0);
        int ans = 0;
        for(auto x:letters) arr[x-'a']++;

        map<pair<int,vector<int>>,int> mpp;
        
        return solve(0,words,arr,score,mpp);
        return ans;
    }
};