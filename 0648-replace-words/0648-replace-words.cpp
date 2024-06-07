class Solution {
public:
    string replaceWords(vector<string>& arr, string line) {
        unordered_set<string> stt(arr.begin(),arr.end());

        int n = line.size();
        string ans = "";
        for(int i=0;i<n;i++)
        {
            string str = "";
            int j=i, s=0;

            while(j<n && line[j] != ' ')
            {
                str += line[j++];
                if(!s && stt.count(str))
                {
                    ans+= str;
                    s=1;
                }
            }
            if(!s)
            {
                ans+=str;
            }
            ans += " ";
            i=j;
        }
        ans.pop_back(); //removes the last extra space
        return ans;
        
    }
};