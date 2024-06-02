/**
 * @param {number[]} bloomDay
 * @param {number} m
 * @param {number} k
 * @return {number}
 */
var calc = function(arr, k, mid)
{
    //we need atleast k adj flowers to make 1 mala, and the curr day is mid
    let cnt = 0, cntt=0;

    for(var i=0;i<arr.length;i++)
    {
        if(arr[i] > mid)    cntt = 0;
        else cntt++;

        if(cntt === k)  
        {
            cnt++;
            cntt= 0;
        }
    }
    return cnt;
}
var minDays = function(bloomDay, m, k) {
    var lo = 1, hi = 1e9;
    var ans = -1;
    while(lo<=hi)
    {
        let mid = Math.floor(lo + (hi-lo)/2);

        let mala = calc(bloomDay,k,mid);
        if(mala >= m)
        {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid +1;
    }
    return ans;
};