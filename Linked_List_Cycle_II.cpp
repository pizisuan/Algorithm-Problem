/*
 * Problem Description
 *
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 */
 
 // 题意：判断链表中是否有环，如果有，则返回环的始节点。这道题的逻辑性很强，想了很久才想通！！！
 
 /**
 * Definition for singly-linked list.
 * struct ListNode 
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        auto fast = head, slow = head;
        while (true) 
        {
            if (fast == NULL || fast->next == NULL) 
                return NULL;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) 
                break;
        }
        fast = head;
        while (true) 
        {
            if (fast == slow) 
                return fast;
            fast = fast->next;
            slow = slow->next;
        }
    }
};
