class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> stk;
        int i = 0;
        for(auto x:word)
        {
            stk.push(x);

            if(x == ch) break;
        }
        if(stk.top() != ch)   return word;
        // if(j == word.size())

        while(stk.size())
        {
            word[i++] = stk.top();
            stk.pop();
        }
        return word;
    }
};