class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> stt;

        while(n != 1)
        {
            int temp = n;
            if(stt.count(temp)) return 0;
            stt.insert(temp);
            int num = 0;
            while(temp)
            {
                num += (temp%10)*(temp%10);
                temp /= 10;
            }
            n = num;
        }
        return 1;
        
    }
};