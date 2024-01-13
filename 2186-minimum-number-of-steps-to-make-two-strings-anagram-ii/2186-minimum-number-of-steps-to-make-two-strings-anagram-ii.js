/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var minSteps = function(s, t) {
    let arr1 = Array(26).fill(0);
    let arr2 = Array(26).fill(0);
    var n = s.length;
    var m = t.length;

    for(var i=0;i<n;i++)
    {
        arr1[s[i].charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    for(var i=0;i<m;i++)
    {
        arr2[t[i].charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    let cnt = 0;

    for(var i=0;i<26;i++)
    {
        cnt += Math.abs(arr1[i] - arr2[i]);
    }
    return cnt;

    
};