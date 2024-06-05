class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<int,int> mpp1;

        for(auto x:words[0])    mpp1[x-'a']++;

        for(int i=1;i<words.size();i++)
        {
            unordered_map<int,int> mpp;
            for(auto x:words[i])
            {
                if(mpp1[x-'a'] > 0)
                {
                    mpp[x-'a']++;
                    mpp1[x-'a']--;
                }
            }
            mpp1 = mpp;
        }

        vector<string> ans;
        for(auto x:mpp1)
        {
            if(x.second > 0)
            {
                // cout<<x.first<<"\n";
                char ch = x.first + 'a';
                string str(1,ch);
                while(x.second--)
                {
                    ans.push_back(str);
                }
            }   
                // ans.push_back(to_string(x.first));
        }
        return ans;
    }
};