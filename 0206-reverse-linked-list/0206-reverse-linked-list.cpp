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
    //reminder for the future
    // i am writing this comment in Mar 2024
    // but this incident is of Nov 2023
    // a day before Probo intrview maybe, btw that was my first ever interview
    // I was conversing with my brother regarding what is the scene of tech interviews
    // I had solved around 500 questions by then
    // he said that the questions are not always hard but you need to express your thought 
    // throughout the interview while solving.
    // then he said like you have to rev a Linked List
    // show me how you'll do it
    // And thats when I realized I cant do it without the arr method
    // It was embarrasing, but then I took out pen and paper and was able to code it
    // coz its easy duh, but just a gentle reminder
    // you didnt know how to reverse Linked list even after 500 LC questions
public:
    ListNode* temp;
    ListNode* head2;
    int cnt=0;
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;

        while(head)
        {
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
                 
    }
};