class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // long long sum = accumulate(chalk.begin(),chalk.end(),0);
        int sum = 0;
        int n = chalk.size();
        for(int i=0;i<n;i++)
        {
            if(k<chalk[i])  return i;
            sum += chalk[i];
            k-= chalk[i];
        }

        k %= sum;
        // int n = chalk.size();
        for(int i=0;i<n;i++)
        {
            if(k<chalk[i])  return i;
            k-=chalk[i];
        } 
        return 0;
    }
};