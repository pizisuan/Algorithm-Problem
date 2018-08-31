/*
 * Problem Description
 * Reverse a singly linked list.
 *
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 *
 */
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *p = head;

        if (p == nullptr) {
            return nullptr;
        }
        
        while(p->next){
            ListNode *cur = p->next;
            p->next = cur->next;
            cur->next = head;
            head = cur;
        }

        return head;
        
    }
};
