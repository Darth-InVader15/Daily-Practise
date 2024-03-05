class Solution {
public:
    int minimumLength(string s) {
      int n = s.size();
      int lt = 0, rt = n-1;

      while(lt < rt)
      {
          if(s[lt] != s[rt])    break;

          while(s[lt+1] == s[lt])   lt++; // take all same char as pref
          while(rt> lt && s[rt] == s[rt-1]) rt--; //take all same char as suff

          //delete the pref and suff
            lt++; rt--;
      }

      if(lt > rt)   return 0;
      else if(lt == rt) return 1;
      else return 1 + rt-lt;
    }
};