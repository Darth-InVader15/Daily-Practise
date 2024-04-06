class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //just reakize that once you end up with neg value
        // let say start is a and endd is b then, any station
        // between them will also generate endd at b
        // so, just skip to b+1

        // int totcost = accumulate(gas.begin(),gas.end(),0);
        // int totprod = accumulate(cost.begin(),cost.end(),0);

        // if(totprod > totcost)   return -1;

        //brute/greedy
        int ind =0;
        int n = gas.size();
        

        while(ind < n)
        {
            int amt = gas[ind];
            int strt = ind;
            int endd = (ind+1)%n;
            while(amt >= 0)
            {
                amt -=cost[strt];
                if(amt < 0) break;
                amt += gas[endd];

                endd = (endd+1)%n;
                strt = (strt+1)%n;
                if(endd == ind) return ind;
            }
            // cout<<ind<<" --\n";
            if(endd+1 == n || endd+1 < ind) break;
            ind = endd;
        }
        return -1;
        
    }
};