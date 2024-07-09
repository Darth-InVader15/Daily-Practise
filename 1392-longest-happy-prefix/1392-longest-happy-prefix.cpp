class Solution {
    // long long basepower(int k)
    // {
    //     long long base = 128, mod = 1e9+7;
    //     long long res = 1;
    //     while(k)
    //     {
    //         if(k&1) res = (res*base)%mod;
    //         base = (base*base)%mod;
    //         k /=2;
    //     }
    //     return res;
    // }
public:
    string longestPrefix(string s) {
        long long preHash = 0, sufHash = 0, base = 128, mod = 1e9 + 7;
        long long basepower = 1;
        int ind = -1, n = s.size();

        for(int i=0;i<n-1;i++)
        {
            preHash = ((preHash*base) + s[i]-'a'+1)%mod;
            sufHash = (sufHash + ((s[n-1-i]-'a'+1)*basepower))%mod;
            basepower = (basepower*base)%mod;
            // cout<<i<<" "<<preHash<<" "<<sufHash<<endl;

            if(preHash == sufHash) ind = i;
            // {
            //     if(s.substr(0,i+1) == s.substr(n-1-i))  ind = i;
            // }
        }
        return s.substr(0,ind+1);
    }
};