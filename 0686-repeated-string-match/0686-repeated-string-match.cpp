class Solution {
private:
    int mod = 1e9+7;
    int base = 31;
    long long hash(string &str)
    {
        long long h = 0;
        for(auto c :str)
        {
            h = ((h*31) + (c-'a'+1))%mod;
        }
        return h;
    }
    long long expont(int k)
    {
        long long ans = 1;
        while(k)
        {
            if(k&1) ans = (ans*base)%mod;
            base = (base*base)%mod;
            k /=2;
        }
        return ans;
    }
public:
    int repeatedStringMatch(string a, string b) {
        auto c = a;
        int cnt = 0;
        while(a.size()< b.size())
        {
            a += c;
            cnt++;
        }
        if(a.find(b) != -1) return cnt + 1;


        a += c; //1 more for goodluck
        // cout<<a<<endl;

        return (a.find(b) == -1) ? -1 : cnt+2;
        
    }
};