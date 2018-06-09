/*
 * Problem Description
 *
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example, Given input array A = [1,1,2].Your function should return length = 2, and A is now [1,2].
 *
 */
 
/*
 * 题意：在一个排序好的数组里面删除重复的元素。
 * 解决方案：
 * 使用两个游标i和j来处理，假设现在i = j + 1，如果A[i] == A[j]，那么我们递增i，直到A[i] != A[j]。
 * 这时候再设置A[j + 1] = A[i]，同时递增i和j，重复上述过程直到遍历结束。
 */

class solution
{
public:
  int removeDuplicates(int a[], int n)
  {
    if (n == 0)
    {
      return 0;
    }

    int j = 0;
    for (int i = 1; i < n; i++)
    {
      if (a[j] != a[i])
      {
        a[++j] = a[i];     // j++; a[j] = a[i];  j指针移动一位后，将i位置的内容拷贝到j位置
      }
    }
    return j+1;
  }
};
