/*
 * Problem Description
 * Given a matrix A, return the transpose of A.
 * The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.
 *
 * Input: [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[1,4,7],[2,5,8],[3,6,9]]
 *
 */
 
// 题意: 实现矩阵转置
// 思路一：观察矩阵，即重新排列组合（各自取每个向量的同一分量形成新的向量，类似Python中的zip函数） 
vector<vector<int>> transpose(vector<vector<int>>& A) 
{
    vector<vector<int>> res;
    for(int i = 0; i < A[0].size(); ++i)
    {
        vector<int> temp;
        for(auto item : A)
        {
            temp.push_back(item[i]);
        }
        res.push_back(temp);
    }
    return res;
}

// 思路二：根据装置矩阵的性质
vector<vector<int>> tranpose(vector<vector<int>> A) 
{
    int M = A.size(), N = A[0].size();
    vector<vector<int>> B(N, vector<int>(M, 0));
    for (int j = 0; j < N; j++)
        for (int i = 0; i < M; i++)
            B[j][i] = A[i][j];
    return B;
}
