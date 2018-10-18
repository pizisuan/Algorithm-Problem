/*
 * Problem DescriptionYou are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Reverse a singly linked list.
 * Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
 * Find out how many ways to assign symbols to make sum of integers equal to target S.
 *
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 *
 * Explanation: 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 *
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 */
 
// 动态规划：需仔细揣摩！！！
class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        int sum = 0;
        for (auto n : nums) 
            sum += n;
        if ((sum + S) % 2 == 1 || S > sum || S < -sum) 
            return 0;
        int new_s = (sum + S) / 2;
        vector<int> dp(new_s + 1, 0);
        dp[0] = 1;

        for (int var : nums)
        {
            for (int j = new_s; j >=var; --j) 
            {
                dp[j] += dp[j - var];
            }
        }
        return dp[new_s];
    }
};
