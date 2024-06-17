class Solution {
public:
    bool judgeSquareSum(int c) {
        int strt=0,endd = sqrt(c)+1;
        long long pro=1;

        while(strt<=endd)
        {
            pro = (strt*strt)+(endd*endd);
            if(pro == c)    return 1;
            else if(pro > c)    endd--;
            else strt++;
        }
        return 0;
    }
};