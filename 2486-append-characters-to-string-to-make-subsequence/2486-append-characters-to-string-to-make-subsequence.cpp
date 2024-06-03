class Solution {
public:
    int appendCharacters(string s, string t) {
        vector<queue<int>> arr(26);
        int n = s.size(), m = t.size();
        for(int i=0;i<n;i++)
        {
            arr[s[i]-'a'].push(i); //we store the indices of all the chars in ascending order
        }
        int lt = -1, cnt = 0;
        for(auto x:t)
        {
            if(arr[x-'a'].size() == 0)  break; //the curr alphabet is not in s
            else
            {
                //lt is the curr index of s that we choose from, so the next char should be on the right of lt
                while(!arr[x-'a'].empty() && arr[x-'a'].front() <= lt)  arr[x-'a'].pop(); 
                if(arr[x-'a'].empty())  break; //if no char on the right
                else
                {
                    cnt++;
                    lt = arr[x-'a'].front(); //set the new lt
                    arr[x-'a'].pop(); //as we used this ind, we remove it
                }
            }
        }
        return m-cnt;
    }
};