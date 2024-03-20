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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int cnt = 0;

        auto temp = list1;
        auto temp2 = list2;
        auto tempEnd = list1, tempStrt = list1, list2End = list2;

        while(temp2)
        {
            if(temp2->next == NULL)  list2End = temp2;
            temp2 = temp2->next;
        }
        while(temp)
        {
            temp = temp->next;
            cnt++;

            if(cnt == a-1)
            {
                tempEnd = temp;     // where we will inject the second list             
            }
            if(cnt == b)
            {
                tempStrt = temp->next; // where the second list will point to
                break;
            }
        }
        tempEnd->next = list2;
        list2End->next = tempStrt;
        return list1;
    }
};