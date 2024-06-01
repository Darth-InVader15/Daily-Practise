class Solution {
public:
//brute force 
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();

        for(int i=0;i<n;i++)
        {
            int num = arr[i];

            for(int k=i+1;k<n;k++) // We creating the sliding window
            {
                num ^= arr[k];
                if(num == 0)    //we have encountered a case of 2 same xors
                {
                    ans += k-i; // this is because a^(b^c) == a^b^c 
                    //so the location of j is not imp
                }
            }
        }
        return ans;
    }
};