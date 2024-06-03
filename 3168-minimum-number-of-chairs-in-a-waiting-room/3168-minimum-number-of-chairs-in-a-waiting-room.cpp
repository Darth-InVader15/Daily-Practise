class Solution {
public:
    int minimumChairs(string s) {
        int maxx = 0;
        int cnt = 0;

        for(auto x:s)
        {
            if(x == 'E')    cnt++;
            else cnt--;
            maxx = max(cnt,maxx);
        }
        return maxx;
    }
};