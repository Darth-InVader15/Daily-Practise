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
// was thinking of this using vector, my man used stack
//could have done it, but its 6 o clock and I cant think with my coffee filled sleepy brain
    ListNode* removeNodes(ListNode* head) {
        auto ptr = head; 
        stack<ListNode*> S, T;
        while (ptr) {
            S.push(ptr);
            ptr = ptr->next;
        }
        int _max = 0;
        while (!S.empty()) {
            // keep this element
            auto node = S.top();
            if (node->val >= _max) {
                _max = max(node->val, _max);
                T.push(node);
            }
            S.pop(); 
        }
        ListNode* h = T.empty() ? nullptr : T.top();
        ListNode* p = h;
        while (p && !T.empty()) {
            T.pop();
            p->next = T.empty() ? nullptr : T.top();
            p = p->next;
        }
        return h;
    }
};