class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        deque<int> dq;
        vector<int> ans;

        for(auto x:nums)
        {
            int num = x*x;
            if(dq.empty())  dq.push_back(num);
            else
            {
                if(num <= dq.front()) dq.push_front(num);
                else if(num >= dq.back()) dq.push_back(num);
                else
                {
                    while(num > dq.front())
                    {
                        ans.push_back(dq.front());
                        dq.pop_front();
                    }
                    dq.push_front(num);
                }
            }
        }
        while(!dq.empty())
            {
                ans.push_back(dq.front());
                dq.pop_front();
            }
        return ans;
    }
};