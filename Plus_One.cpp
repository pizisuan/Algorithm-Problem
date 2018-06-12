/*
 * Problem Description
 *
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 * The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
 */
 
/*
 * 题意：Input: [1,2,3]   Output: [1,2,4]
 * 解决方案：考察加法进位
 *
 */

class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        vector<int> res(digits.size(), 0);
        int sum = 0;
        int one = 1; 
        
        for(int i = digits.size()-1; i >= 0; i--)
        {
            sum = one + digits[i];
            one = sum / 10;          // 计算进位
            res[i] = sum % 10;
        }
        
        if(one > 0)
        {
            res.insert(res.begin(),one);
        }
        
        return res;
    }
};
