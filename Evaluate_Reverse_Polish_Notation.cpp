/*
 * Problem Description
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Example 1:
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 *
 * Example 2:
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 *
 * Example 3:
 * Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * Output: 22
 * Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5 = 22
 */
 
// 考察数据结构---栈 
class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> res;
        for (string var : tokens)
        {
            if ((var != "+") && (var != "-") && (var != "*") && (var != "/"))
            {
                res.push(stoi(var));
            }
            else
            {
                int right = res.top();
                res.pop();
                int left = res.top();
                res.pop();

                if (var == "+")
                    res.push(left + right);
                else if (var == "-")
                    res.push(left - right);
                else if (var == "*")
                    res.push(left * right);
                else
                    res.push(left / right);
            }
        }
        return res.top();
    }
};
