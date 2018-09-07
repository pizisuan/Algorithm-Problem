/*
 * Problem Description
 *
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
 
// 自己第一版程序， 思路：先比较两链表长度大小，将指针指向长的链表，进行计算。
// 1563 test cases passed. Runtime: 76 ms

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        
        ListNode *p1 = l1, *p2 = l2;

        while (p1 && p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode *head = p1 ? l1 : l2;
        ListNode *tail = head;

        int add = 0;
        while (l1 && l2)
        {
            int cur_val = (l1->val + l2->val + add) % 10;
            add = (l1->val + l2->val + add) / 10;
            tail->val = cur_val;
            l1 = l1->next;
            l2 = l2->next;
            if (l1 == NULL && l2 == NULL)
            {
                if (add != 0)
                {
                    tail->next = new ListNode(add);
                    return head;
                }
                
            }
            tail = tail->next;
        }
        while (tail)
        {
            int cur_val = (tail->val + add) % 10;
            add = (tail->val + add) / 10;
            tail->val = cur_val;
            if (tail->next == NULL)
            {
                if (add != 0)
                {
                    tail->next = new ListNode(add);
                    return head;
                }
            }
            tail = tail->next;
        }
        return head;
          
    }
};


// 自己改进的第二版程序：无需比较长度，节省时间
// 1563 test cases passed. Runtime: 28 ms

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        
        ListNode *head = l1;
        ListNode *tail = l1;

        int add = 0;
        while (l1 && l2)
        {
            int cur_val = (l1->val + l2->val + add) % 10;
            add = (l1->val + l2->val + add) / 10;
            tail->val = cur_val;
            l1 = l1->next;
            l2 = l2->next;
            if (l1 == NULL && l2 == NULL)
            {
                if (add != 0)
                {
                    tail->next = new ListNode(add);
                    return head;
                }
                
            }
            else if (l1 == NULL)
            {
                tail->next = l2;
            }
            tail = tail->next;
        }
        while (tail)
        {
            int cur_val = (tail->val + add) % 10;
            add = (tail->val + add) / 10;
            tail->val = cur_val;
            if (tail->next == NULL)
            {
                if (add != 0)
                {
                    tail->next = new ListNode(add);
                    return head;
                }
            }
            tail = tail->next;
        }
        return head;     
    }
};
