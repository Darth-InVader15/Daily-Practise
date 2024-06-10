class Solution {
public:
    int heightChecker(vector<int>& arr) {
        auto temp = arr;
        sort(temp.begin(),temp.end());
        int n = arr.size(), cnt=0;
        for(int i=0;i<n;i++)    if(arr[i] != temp[i])   cnt++;
        return cnt;
        
    }
};