/*
 * Problem Description
 *
 * Follow up for "Remove Duplicates": What if duplicates are allowed at most twice?
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example, Given sorted array A = [1,1,1,2,2,3],Your function should return length = 5, and A is now [1,1,2,2,3].
 *
 */
 
/*
 * 题意：在一个排序好的数组里面删除重复的元素,但是可以允许最多两次重复元素存在。。
 * 解决方案：
 * 需要用一个计数器来记录重复的次数，如果重复次数大于等于2，我们会按照第一题的方式处理，如果不是重复元素了，我们将计数器清零。
 */

class solution
{
public:
  int removeDuplicates(int* nums, int numsSize) 
  {
    if (numsSize == 0)
    {
      return 0;
    }
    int j = 0;
    int times = 0;  // 重复次数记录
    for (int i = 1; i < numsSize; i++)
    {
      if (nums[j] == nums[i])
      {
        times++;
        if (times < 2)
        {
          nums[++j] = nums[i];
        }
      }
      else
      {
        nums[++j] = nums[i];
        times = 0;
      }
    }
    return j+1;
  }
};
