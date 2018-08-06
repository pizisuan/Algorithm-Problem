/*
 * Problem Description
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 * 
 * Input:
 * [
 *    [ 1, 2, 3 ],
 *    [ 4, 5, 6 ],
 *    [ 7, 8, 9 ]
 * ]
 *
 * Output:  [1,2,3,6,9,8,7,4,5]
 */
 
 
 
class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if (matrix.empty())
        {
            return {};
        }

        int m = matrix.size();
        int n = matrix[0].size();

        int up = 0, right = n - 1, down = m - 1, left = 0, index = 0;

        vector<int> res (m * n);

        while (true)
        {
            // up
            for (int col = left; col <= right; col++)
            {
                res[index++] = matrix[up][col];
            }
            if (++up > down)
            {
                break;
            }

            // right
            for (int row = up; row <= down; row++)
            {
                res[index++] = matrix[row][right];
            }
            if (--right < left)
            {
                break;
            }

            // down
            for (int col = right; col >= left; col--)
            {
                res[index++] = matrix[down][col];
            }
            if (--down < up )
            {
                break;
            }

            // left
            for (int row = down; row >= up; row--)
            {
                res[index++] = matrix[row][left];
            }
            if (++left > right)
            {
                break;
            }
        }
        return res;
    }
};
