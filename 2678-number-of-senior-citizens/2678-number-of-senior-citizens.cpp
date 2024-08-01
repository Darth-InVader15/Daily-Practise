class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0,age;
        string temp;
        
        for(auto x:details)
        {
            temp = x.substr(11,2);
            // cout<<temp<<endl;
            age = stoi(temp);
            if(age > 60)    cnt++;
        }
        return cnt;
    }
};