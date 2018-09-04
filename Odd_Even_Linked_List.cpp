/*
 * Problem Description
 *
 * Given a singly linked list, group all odd nodes together followed by the even nodes.
 * Please note here we are talking about the node number and not the value in the nodes.You should try to do it in place.
 * The program should run in O(1) space complexity and O(nodes) time complexity.
 *
 * Example 1:
 * Input: 1->2->3->4->5->NULL
 * Output: 1->3->5->2->4->NULL
 *
 * Example 2:
 * Input: 2->1->3->5->6->4->7->NULL
 * Output: 2->3->6->7->1->5->4->NULL
 *
 *
 */



//自己的代码:设置奇偶两个指针分别将各自的节点连接起来，最后再将奇偶链表连接起来（注意条件的判断）
class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        ListNode *flag = head->next;
        while (p1 && p1->next && p2 && p2->next)
        {
            if (p1->next->next != NULL)
            {
                p1->next = p1->next->next;
                p2->next = p2->next->next;
                p1 = p1->next;
                p2 = p2->next;
            }
            else 
                break;
        }
        p1->next = flag;
        return head;
    }
};
