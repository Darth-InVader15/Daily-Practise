class Solution {
    int ans = 1e9;
    void bfs(string &strt, string &endd,unordered_set<string> &stt,unordered_set<string> &vis)
    {
        if(strt == endd)
        {
            ans = 0;
            return;
        }

        queue<pair<int,string>> q;
        q.push({1,strt});

        while(!q.empty())
        {
            auto str = q.front().second;
            int cnt = q.front().first;
            q.pop();

            if(str == endd)
            {
                ans = min(cnt,ans);
                continue;
            }

            for(int i=0;i<str.size();i++)
            {
                auto temp = str;
                for(int j=0;j<26;j++)//all alphabets covered
                {
                    temp[i] = j+'a';
                    if(stt.count(temp) && !vis.count(temp))
                    {
                        q.push({cnt+1,temp});
                        vis.insert(temp);
                    }
                    temp[i] = str[i];
                }
            }
        }
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> stt(wordList.begin(),wordList.end());
        unordered_set<string> vis;

        if(!stt.count(endWord)) return 0;
        bfs(beginWord,endWord,stt,vis);

        return ans == 1e9 ? 0 : ans;

    }
};