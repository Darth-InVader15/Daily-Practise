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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int ind = 1;
        auto prev = head;
        auto temp = head->next;
        vector<int> pts;
        int minn = 1e9, maxx = 0;
        vector<int> ans(2,-1);

        while(temp->next)
        {
            if(temp->val > prev->val && temp->val > temp->next->val)
            {
                if(pts.size())  minn = min(minn,ind-pts.back());
                pts.push_back(ind);
            }
            if(temp->val < prev->val && temp->val < temp->next->val)
            {
                if(pts.size())  minn = min(minn,ind-pts.back());
                pts.push_back(ind);
            }
            
            prev = temp;
            temp = temp->next;
            ind++;

        }
        if(pts.size()<2) return ans;
        maxx = pts.back()-pts[0];
        ans[0] =minn, ans[1] = maxx;
        return ans;
        
    }
};