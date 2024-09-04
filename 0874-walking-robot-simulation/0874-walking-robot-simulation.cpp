class Solution {
public:
    int robotSim(vector<int>& coms, vector<vector<int>>& arr) {
        set<vector<int>> stt(arr.begin(),arr.end());

        int tx = 0, ty = 0;
        int dirn =0;
        int dist, ans = INT_MIN;
        for(auto t:coms)
        {
            if(t<0)
            {
                if(t==-1)
                {
                    dirn = (dirn+1)%4;
                    // dirn++;
                }
                else
                {
                    dirn = dirn>0 ? dirn-1 : 3;
                    // dirn++;
                }
            }
            else
            {
                int k = t;
                switch((dirn+1))
                {
                    case 1:
                    while(k--)
                    {
                        if(stt.count({tx,ty+1}))    break;
                        ty++;
                    }
                    break;
                    case 2:
                    while(k--)
                    {
                        if(stt.count({tx+1,ty}))    break;
                        tx++;
                    }
                    break;
                    case 3:
                    while(k--)
                    {
                        if(stt.count({tx,ty-1}))    break;
                        ty--;
                    }
                    break;
                    case 4:
                    while(k--)
                    {
                        if(stt.count({tx-1,ty}))    break;
                        tx--;
                    }
                    break;
                }
                // cout<<tx<<" "<<dirn<<" "<<ty<<endl;
                dist = (tx*tx) + (ty*ty);
                ans = max(ans,dist);
            }
        }
        return ans;

    }
};