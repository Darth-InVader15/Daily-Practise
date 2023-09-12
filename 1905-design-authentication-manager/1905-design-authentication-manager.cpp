class AuthenticationManager {
public:
unordered_map<string,int>mpx;
int time = 0;
    AuthenticationManager(int timeToLive) {
        time = timeToLive;
    }
    
    void generate(string tokenId, int curr) {
        mpx[tokenId] = curr + time;
        
    }
    
    void renew(string tokenId, int curr) {
        if(mpx.find(tokenId) == mpx.end() || mpx[tokenId] == 1e9) return;

        if(mpx[tokenId] > curr)
        {
            mpx[tokenId] = curr+time;
        }
        
    }
    
    int countUnexpiredTokens(int curr) {
        // auto mpx = AuthenticationManager->mpp;
        int cnt = 0;
        for(auto x:mpx)
        {
            // cout<<x.second<<" "<<x.first<<"\n";
            if(x.second <= curr || x.second >= 1e9)
                mpx[x.first] = 1e9;
            else
                cnt++;
        }
        return cnt;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */