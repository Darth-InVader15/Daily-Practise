class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        int cnt = 0 ;
        unordered_map<int,int> mpp;
        int n = hand.size();
        if(n%gs)    return 0; //cant be divided into groups

        for(auto x:hand)    mpp[x]++;
        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++)
        {
            if(mpp[hand[i]] > 0)
            {
                int s = 0;
                for(int j=1;j<gs;j++)
                {
                    if(mpp[hand[i]+j] > 0)    continue;
                    else
                    {
                        s = 1;
                        break;
                    }
                }
                if(!s)
                {
                    cnt++;
                    for(int j=0;j<gs;j++)
                    {
                        mpp[hand[i]+j]--;
                        // cout<<i<<" "<<j<<endl;
                    }
                }
            }
            // if(cnt == groupSize)    return 1;
        }
        // cout<<cnt<<endl;
        return (cnt == n/gs);
        return 0;
    }
};