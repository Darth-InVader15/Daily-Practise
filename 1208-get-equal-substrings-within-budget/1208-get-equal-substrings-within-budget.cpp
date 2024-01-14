class Solution {
public:
    int equalSubstring(string s, string t, int maxcost) {

        int n = s.size(),sum = 0,ans = 0;
        vector<int>cost(n,0);

        for(int i = 0;i<n;i++)
        cost[i] = abs(s[i]-t[i]);

        queue<int> q;
	    for(int i=0;i<n;i++)
	    {
	      if(sum+cost[i]<=maxcost)
	      {
	        sum+=cost[i];
	        q.push(cost[i]);
	        if(ans<q.size())
	            ans=q.size();
	      }
	      else if(q.size()>0)
	      {
	        sum-=q.front();
	        q.pop();
	        i--;
	      }
	    }

        return ans;
        
    }
};