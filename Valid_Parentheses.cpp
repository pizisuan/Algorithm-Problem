/*
 * Problem Description
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 * Input: "()"
 * Output: true
 * 
 * Example 2:
 * Input: "()[]{}"
 * Output: true
 *
 * Example 3:
 * Input: "(]"
 * Output: false
 *
 * Example 4:
 * Input: "([)]"
 * Output: false
 *
 * Example 5:
 * Input: "{[]}"
 * Output: true
 */

// 非常经典的算法题：考察数据结构---栈
class Solution 
{
public:
    bool isValid(string k) 
    {
        if (k.empty())
            return true;
        stack<char> s;
        for (char var : k)
        {
            if (var == '(' || var == '[' || var == '{')
            {
                s.push(var);
            }
            else
            {
                if (s.size() == 0)
                {
                    return false;
                }
                if (var == ')')
                {
                    if (s.top() != '(')
                    {
                        return false;
                    }
                    s.pop();
                }
                else if (var == ']')
                {
                    if (s.top() != '[')
                    {
                        return false;
                    }
                    s.pop();
                }
                else
                {
                    if (s.top() != '{')
                    {
                        return false;
                    }
                    s.pop();
                }
            }
        }
        return s.size()== 0;
    }
};
