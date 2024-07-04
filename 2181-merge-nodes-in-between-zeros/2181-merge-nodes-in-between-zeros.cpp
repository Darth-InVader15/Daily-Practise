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
    ListNode* mergeNodes(ListNode* head) {
        auto temp = head;
        ListNode* head2 = NULL;
        auto temp2 = head2;
        while(temp)
        {
            int cnt = 0;
            if(temp->val == 0)
            {
                temp = temp->next;
                while(temp && temp->val != 0)
                {
                    cnt += temp->val;
                    temp = temp->next;
                }
                if(cnt == 0)    continue;
                auto node = new ListNode(cnt);
                if(!head2)
                {
                    head2 = node;
                    temp2 = node;
                }
                else
                {
                    temp2->next = node;
                    temp2 = temp2->next;
                }
                
            }
        }
        return head2;
        
    }
};