class Solution {
    int m,x, cnt=0;
    string ans = "";
    void solve(string anss,unordered_set<int> &stt)
    {
        // cout<<anss<<" "<<cnt<<"==\n";
        if(anss.size() == m) cnt++;
        if(cnt == x && anss.size() == m)
        {
            ans = anss;
            return;
        }

        for(int i=1;i<=m;i++)
        {
            if(stt.count(i))    continue;
            anss += (i+'0');
            stt.insert(i);
            // ++cnt;/
            solve(anss,stt);

            //backtrack
            stt.erase(i);
            anss.pop_back();
        }
    }
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        for(int i=1;i<n;i++){
            // To find (n-1)!
            fact = fact*i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans="";
        k = k-1;
        while(true){
            //Add the first element of reqd permutation
            ans = ans + to_string(numbers[k/fact]);
            //Erase that element from vector 
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.size()==0) break;
            //Find the position for remaining elements
            k = k%fact;
            //Find the reqd factorial
            fact = fact/numbers.size();
        }
        return ans;
    }
};