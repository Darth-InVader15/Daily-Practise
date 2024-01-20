class Solution {
public:
// Monotonic stack
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();

        //we store the the dist of the next min ele to the left and right in 2 diff arrs
        vector<int> lt(n), rt(n,n);
        stack<int> stk1, stk2;

        //for calculating the left arr eles
        for(int i=0;i<n;i++)
        {
            //jabtak stack ka ele greater ho curr num se, we will ignore them 
            //as unka subset with curr ele m value toh curr ele ka hi aayega (min)
            while(!stk1.empty() && arr[stk1.top()] > arr[i])  stk1.pop();

            //itne subsets m min i hai 
            if(stk1.empty()) lt[i] = i+1;
            else lt[i] = i-stk1.top();
            stk1.push(i);
        }
        //for the rt min ele
        for(int i = n-1;i>=0;i--)
        {
            while(!stk2.empty() && arr[stk2.top()] >= arr[i])   stk2.pop();

            if(stk2.empty())    rt[i] = n-i;
            else rt[i] = stk2.top() - i;
            stk2.push(i);
        }

        //So the lt and rt stores the num of subsets for which i is the lowest ele
        // this means their sum would be arr[i] * lt[i] * rt[i]
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = (ans + (1ll * arr[i] * lt[i] * rt[i])%mod)%mod;
        }
        return ans;

        
    }
};