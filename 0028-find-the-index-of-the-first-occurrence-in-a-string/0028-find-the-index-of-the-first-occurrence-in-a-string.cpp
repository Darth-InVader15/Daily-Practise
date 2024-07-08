class Solution{
private:
    const int mod = 1e9 + 7;
    const int base = 31;

    //Rolling Hash aka Rabin Karp
    // I tried a solution after watching a TLE eliminators videos
    //couldnt handle the overflow for the exponential power

    
    long long hash(string &str) {
        long h = 0;
        int n = str.size();
        for(int i = 0; i < n; i++) {
            h = (h * base + (str[i] - 'a' + 1)) % mod;
        }
        return h;
    }

    long long modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        while(exp > 0) {
            if(exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

public:
    int strStr(string hay, string need) {
        int n = hay.size();
        int m = need.size();
        if(m > n) return -1;

        if(need == hay) return 0;
        
        int needHash = hash(need);
        string temp = hay.substr(0, m);
        int hayHash = hash(temp);
        if(hayHash == needHash && hay.substr(0, m) == need) return 0;

        long long basePower = modExp(base, m - 1, mod);

        for(int i = m; i < n; i++) {
            hayHash = (hayHash - (hay[i - m] - 'a' + 1) * basePower % mod + mod) % mod;
            hayHash = (hayHash * base + (hay[i] - 'a' + 1)) % mod;
            if(hayHash == needHash && hay.substr(i - m + 1, m) == need) return i - m + 1;
        }

        return -1;
    }
};