/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string str;
        ListNode* temp = head;
        while(temp != NULL)
        {
            str.push_back(temp->val);
            temp = temp->next;
        }
        int s = str.size();
        for(int i=0;i<=s/2;i++)
        {
            if(str[i] != str[s-(i+1)])
            return false;
        }
        return true;
        
    }
};