//{ Driver Code Starts
//Initial Template for javascript

"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
  inputString += inputStdin;
});

process.stdin.on("end", (_) => {
  inputString = inputString
    .trim()
    .split("\n")
    .map((string) => {
      return string.trim();
    });

  main();
});

function readLine() {
  return inputString[currentLine++];
}

function main() {
  let t = parseInt(readLine());
  let i = 0;
  for (; i < t; i++) {
    let [n, m] = readLine()
      .trim()
      .split(" ")
      .map((x) => parseInt(x));
    let obj = new Solution();
    let res = obj.NthRoot(n, m);
    console.log(res);
  }
}
// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
class Solution {
  NthRoot(n, m) {
    //code here
    var lo = 0, hi = m;
    
    while(lo<=hi)
    {
        var mid = Math.floor(lo + (hi-lo)/2);
        
        let num = Math.pow(mid,n);
        // console.log(mid + " " + num);
        if(num === m)   return mid;
        else if(num > m)    hi = mid-1;
        else lo = mid+1;
    }
    return -1;
  }
}