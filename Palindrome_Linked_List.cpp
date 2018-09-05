/*
 * Problem Description
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Input: 1->2
 * Output: false
 *
 * Input: 1->2->2->1
 * Output: true
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
 
 
// 我的代码：思路采用递归  
// 26 test cases passed.Runtime: 1184 ms 效率很低！！！
 
class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        if (head == NULL)
            return true;
        ListNode *tail = head;
        while(tail && tail->next)
        {
            if (tail->next->next == NULL)
                break;
            else
                tail = tail->next;
        }
        while (head && tail->next)
        {
            if (head->val == tail->next->val)
            {
                tail->next = NULL;
                return isPalindrome(head->next);
            }
            else
                return false;
        }
        return true;
    }
};

// 别人的代码：思路是将链表中的数据存入一个vector中，然后对vector进行判断。优点是效率高，缺点是额外消耗了存储空间
// 26 test cases passed.Runtime: 12 ms
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        if(!head) 
            return true;
        vector<int> t;
        while(head)
        {
            t.push_back(head->val);
            head=head->next;
        }
        int left=0;
        int right=t.size()-1;
        while(left<right)
        {
            if(t[left]==t[right])
            {
                left++;
                right--;
            }
            else
                return false;
        }
        return true;
    }
};
 
