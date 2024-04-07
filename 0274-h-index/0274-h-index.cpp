class Solution {
public:
    int hIndex(vector<int>& cit) {
        sort(cit.begin(),cit.end());
        int n = cit.size();

        int lo = 0, hi = cit[n-1];
        int ans = 0;
        for(int i=lo;i<hi;i++)
        {
            //lt is the index of the lowest ele >= i
            int lt = lower_bound(cit.begin(),cit.end(),i)-cit.begin();

            int papers = n-(lt);    //no of papers with min i citations

            // cout<<i<<" == "<<lt<<" "<<papers<<endl;

            if(papers >= i)    ans = max(i,ans);
        }
        return ans;

    }
};