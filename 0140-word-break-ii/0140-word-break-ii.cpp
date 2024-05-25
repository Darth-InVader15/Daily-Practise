class Solution {
    vector<string> ans;
    void makeAns(vector<string> &words)
    {
        string temp = "";
        for(auto x: words)  temp += (x + " ");
        temp.pop_back();
        ans.push_back(temp);
    }
    void MCM(int ind, string &str, vector<string> words, unordered_set<string> &dict, set<pair<int,vector<string>>> &mpp)
    {
        if(ind == str.size())
        {
            // ans.push_back(words);
            makeAns(words);
            return;
        }
        if(mpp.count({ind,words}))  return;
        mpp.insert({ind,words});
        string temp = "";

        for(int i=ind;i<str.size();i++)
        {
            temp += str[i];
            // cout<<temp<<endl;
            if(dict.count(temp) > 0)
            {
                cout<<temp<<"-\n";
                words.push_back(temp);
                MCM(i+1,str,words,dict,mpp);
                words.pop_back(); 
            }
        }

    }
public:
    vector<string> wordBreak(string s, vector<string>& dict) {
        unordered_set<string> stt(dict.begin(),dict.end());
        // string temp = "";
        vector<string> temp;
        set<pair<int,vector<string>>> mpp;
        MCM(0,s,temp,stt,mpp);
        return ans;
    }
};