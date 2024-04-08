class Solution {
public:
    int countStudents(vector<int>& stud, vector<int>& sams) {
        queue<int> q;
        stack<int> stk;

        int n = sams.size();
        int s = 0, strt = 0;

        for(int i = n-1;i>=0;i--)
        {
            stk.push(sams[i]);
        }
        for(int i=0;i<n;i++)    q.push(i);
        
        while(q.size())
        {
            if(stud[q.front()] == stk.top())
            {
                q.pop();
                stk.pop();
            }
            else
            {
                int strt = q.front();
                
                while(stk.top() != stud[q.front()])
                {
                    q.push(q.front());
                    q.pop();

                    if(q.front() == strt)
                    {
                        s =1;
                        break;
                    }
                }
                if(s)   break;
            }
        }
        return  q.size();
        
    }
};