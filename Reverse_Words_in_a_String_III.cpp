/*
 * Problem Description
 *
 * Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial 
 * word order.
 *
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 */
 
 
// 大神的代码
class Solution 
{
public:
    string reverseWords(string s) 
    {
        size_t front = 0;
        for (int i = 0; i <= s.length(); ++i)
        {
            if (i == s.length() || s[i] == ' ')
            {
                reverse(&s[front], &s[i]);
                front = i + 1;
            }
        }
        return s;
    }
};


// 自己的代码: 先获取每个word,对每个word进行反转，然后添加到最终结果；而大神的代码直接遍历的同时进行反转，无需额外内存空间。
class Solution 
{
public:
    string reverseWords(string s) 
    {
        string current, res;
        for (char var : s)
        {
            if (var != ' ')
            {
                current += var;
            }
            else
            {
                reverse(current.begin(), current.end());
                res = res + current + var;
                current = "";
            }

        }
        reverse(current.begin(), current.end());
        return res + current;       
    }
};
