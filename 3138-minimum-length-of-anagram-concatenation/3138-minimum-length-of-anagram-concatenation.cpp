class Solution {
public:
    int minAnagramLength(string s) {
        //so hint 1 says that the size m should be a divisor of n;
        // i is the size of the string we are considering
        int n = s.size();
        for(int i=1;i<=n;i++)
        {
            if(n%i != 0)    continue;
            string temp = s.substr(0,i);
            sort(temp.begin(),temp.end());
            int c = 0;

            for(int j=i;j<n;j+=i)
            {
                string temp2 = s.substr(j,i);
                sort(temp2.begin(),temp2.end());

                if(temp != temp2)
                {
                    c = 1;
                    break;
                }
            }

            if(!c)  return i;
        }
        return n;
    }
    
};