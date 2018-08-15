/*
 * Problem Description
 *
 * Given a binary array, find the maximum number of consecutive 1s in this array.
 *
 * Input: [1,1,0,1,1,1]
 * Output: 3
 *
 * Explanation:
 * The first two digits or the last three digits are consecutive 1s.The maximum number of consecutive 1s is 3.
 */


class Solution 
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int sum = 0;
        int res = 0;
        for (int var : nums)
        {
            if (var)
                sum++;
            else
            {
                if (sum > res)
                    res = sum;
                sum = 0;
            }
        }
        return sum > res ? sum : res;        
    }
};
