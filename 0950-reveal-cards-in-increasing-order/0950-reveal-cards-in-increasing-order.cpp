class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& arr) {
        // we will reverse this process using deque to get our desired arr
        int i = 1, n = arr.size();
        deque<int> dq;
        sort(arr.begin(),arr.end(),greater<int>());

        dq.push_back(arr[0]);

        // we move last ele to front and then add new ele
        while(i < n)
        {
            int back = dq.back();
            dq.push_front(back);
            dq.pop_back();
            
            // cout<<arr[i]<<" "<<back<<"--\n";
            dq.push_front(arr[i++]);
        }

        
        i=0;
        vector<int> ans(n);
        while(!dq.empty())
        {
            // cout<<dq.front()<<"--\n";
            if(i == n) break;
            ans[i++] = dq.front();
            dq.pop_front();
        }
        return ans;
    }
};