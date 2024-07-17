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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> stt(nums.begin(),nums.end());
        

        while(head && stt.count(head->val))
        {
            head = head->next;
        }

        auto temp = head;
        
        while(temp && temp->next)
        {
            if(stt.count(temp->next->val))
            {
                temp->next = temp->next->next;
            }
            else temp = temp->next;
        }
        return head;

    }
};