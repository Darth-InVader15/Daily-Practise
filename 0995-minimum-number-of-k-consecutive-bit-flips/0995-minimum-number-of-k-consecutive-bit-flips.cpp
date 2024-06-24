class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        set<int> stt;
        int cnt = 0;
        int ans = 0;

        for(int i=0;i<=nums.size()-k;i++)
        {
            if(stt.count(i))
            {
                stt.erase(i);
                cnt--; //one of the k-flips ended here
            }
            if((cnt%2 == 0 && !nums[i]) || (cnt%2 != 0 && nums[i]))//encountered a zero
            {
                cnt++; // current active flips
                stt.insert(i+k);
                ans++; // total count of flips
            }
        }
        for(int i=1+nums.size()-k;i<nums.size();i++)
        {
           if(stt.count(i))
            {
                stt.erase(i);
                cnt--; //one of the k-flips ended here
            } 
            if((cnt%2 == 0 && !nums[i]) || (cnt%2 != 0 && nums[i]))//encountered a zero
            {
                return -1; // k ele cant be selected from here
            }
        }
        return ans;
    }
};