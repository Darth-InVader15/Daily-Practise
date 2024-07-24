class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> arr;

        for(auto x:nums)
        {
            int num = 0;
            int i=0;
            if(x == 0)  num = mapping[x];
            while(x)
            {
                num += (mapping[(x%10)] * pow(10,i++));
                x /=10;
            }
            arr.push_back(num);
        }
        for(auto x:arr) cout<<x<<" ";
        cout<<endl;
        vector<pair<int,int>> temp;

        for(int i=0;i<nums.size();i++)
        {
            temp.push_back({arr[i],i});
        }
        sort(temp.begin(),temp.end());

        vector<int> ans;
        for(auto x:temp)    ans.push_back(nums[x.second]);
        return ans;
        
    }
};