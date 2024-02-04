class Solution {
    bool chk(unordered_map<char,int> &mpp)
    {
        for(auto itr:mpp)
        {
            //there is an element missing
            if(itr.second > 0)  return 0;
        }
        return 1;
    }
    string toStr(deque<char> anss)
    {
        string str ="";
        while(!anss.empty())
        {
            str += anss.front();
            anss.pop_front();
        }
        return str;
    }
public:
    string minWindow(string s, string t) {
        // unordered_map<char,int> mpp;
        unordered_multiset<char> stt;
        unordered_map<char, int> mpp;

        if(s.size() < t.size()) return "";

        for(auto c :t)
        {
            stt.insert(c);
            mpp[c]++;
        }

        deque<char> dq, anss;
        int ans = INT_MAX;

        for(auto x:s)
        {
            if(dq.empty() && !stt.count(x)) continue;
            
            if(1)
            {
                dq.push_back(x);
                if(stt.count(x))
                {
                    mpp[x]--;
                }

                if(chk(mpp))
                {
                    if(dq.size() < ans)
                    {
                        ans = dq.size();
                        anss = dq;
                    }

                    if(stt.count(dq.front()))
                    {
                        mpp[dq.front()]++;
                        dq.pop_front();

                        // cout<<x<<" "<<toStr(dq)<<" "<<chk(mpp)<<endl;

                        while(!dq.empty() && (!stt.count(dq.front()) || mpp[dq.front()] < 0)) 
                        {
                            if(stt.count(dq.front()))   mpp[dq.front()]++;
                            dq.pop_front();
                        }

                        if(chk(mpp))
                        {
                            if(dq.size() < ans)
                            {
                                ans = dq.size();
                                anss = dq;
                            }
                        }
                    }
                }
            }
            // else
            // {
            //     if(stt.count(dq.front()))
            //     {
            //         mpp[dq.front()]++;
            //         dq.pop_front();

            //         cout<<x<<" "<<chk(mpp)<<endl;

            //         while(!dq.empty() && !stt.count(dq.front()))   dq.pop_front();

            //         dq.push_back(x);
            //         if(stt.count(x))    mpp[x]--;

            //         if(chk(mpp))
            //         {
            //            if(dq.size() < ans)
            //             {
            //                 ans = dq.size();
            //                 anss = dq;
            //             }
            //         }
            //     }
            // }
        }

        string str = "";
        if(ans == INT_MAX)  return str; // it means we never got out ans

        while(!anss.empty())
        {
            str += anss.front();
            anss.pop_front();
        }
        return str;

        
    }
};