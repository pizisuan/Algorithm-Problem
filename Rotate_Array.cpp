/*
 * Problem Description
 *
 * Given an array, rotate the array to the right by k steps, where k is non-negative.
 * 
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 *
 * Output:  [1,2,4,7,5,3,6,8,9]
 */
 
 
class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        int count = k % nums.size();
        vector<int> res;
        for (int i = nums.size() - count; i < nums.size(); i++)
        {
            res.push_back(nums[i]);
        }
        for (int j = 0; j < nums.size() - count; j++)
        {
            res.push_back(nums[j]);
        }
        nums = res;        
    }
};
