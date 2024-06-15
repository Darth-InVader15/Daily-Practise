class Solution {
    bool static cstm(pair<int,int> &a, pair<int,int> &b)
    {
        if(a.first < b.first)   return 1;
        else if(a.first == b.first && a.second > b.second)  return 1;
        return 0;
    }
public:
    int findMaximizedCapital(int n, int w, vector<int>& prof, vector<int>& cap) {
        int k = cap.size();
        vector<pair<int,int>>arr;

        for(int i=0;i<k;i++)    arr.push_back({cap[i],prof[i]});
        sort(arr.begin(),arr.end());
        priority_queue<int> pq;
        int curr = 0;

        while(n--)
        {
            while(curr<k && arr[curr].first<=w)
            {
                cout<<curr<<"--"<<arr[curr].second<<"\n";
                pq.push(arr[curr].second);      //for any given w, we are collecting all possible jobs
                curr++;
            }

            if(!pq.empty())
            {
                cout<<w<<"---\n";
                w += pq.top();    //pq has the job with the highest profit for the curr w
                pq.pop();
            }
            else break; //all jobs done
        }
        return w;        
    }
};