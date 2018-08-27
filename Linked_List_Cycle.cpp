/*
 * Problem Description
 *
 * Given a linked list, determine if it has a cycle in it.
 *
 */
 
//思路：设置快慢两个指针，慢指针步长为1，快指针步长为2。如果链表无环，那么快指针比慢指针先到链尾；如果链表有环，那么快指针将会在某一时刻与慢指针重合。 

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};
