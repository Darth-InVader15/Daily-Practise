class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string str = "";

        int n = path.size();

        // for(int i=0;i<n;i++)
        // {
        //     str += path[i];
        //     if(path[i] == '/')
        //     {
        //         while(i+1 < n && path[i+1] == '/') i++;
        //     }
        // }
        // path = str;

        cout<<str<<endl;

        stk.push("/");

        for(int i=1;i<n;i++)
        {
            string temp = "";
            // cout<<stk.top()<<" "<<stk.size()<<endl;

            while(i<n && path[i] != '/')
            {
                temp += path[i++];
            }

            // cout<<temp<<" --\n";

            if(temp == "..")
            {
                if(stk.size() >= 3)  
                {
                    stk.pop();
                    stk.pop();
                    continue;
                }
                // else stk.pop();
                else continue;
            }
            else if(temp == ".")
            {
                continue;
                // 
                //just remove the prev /
            }
            else if(temp == "")
            {
                // there are 2 //
                continue;
            }
            else
            {
                stk.push(temp);
            }
            stk.push("/");
        }
        if(stk.top() == "/" && stk.size() > 1)    stk.pop();

        string ans = "";
        stack<string> q;

        while(stk.size())
        {
            q.push(stk.top());
            stk.pop();
        }
        while(q.size())
        {
            ans += q.top();
            q.pop();
        }
    //    reverse(ans.begin(),ans.end());
        return ans;// .size() ? ans : "/";
    }
};