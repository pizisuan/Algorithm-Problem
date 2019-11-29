/*
 * Problem Description
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
 * The distance between two adjacent cells is 1.
 *
 *
 * Example 1
 * Input:[[0,0,0],[0,1,0],[0,0,0]]
 * Output: [[0,0,0],[0,1,0],[0,0,0]]
 *
 * Example 2
 * Input:[[0,0,0],[0,1,0],[1,1,1]]
 * Output: [[0,0,0],[0,1,0],[1,2,1]]
 *
 *
 */



class Solution_Leetcode542
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix);
private:
    // 广度优先搜索
    int BFS(vector<vector<int>>& matrix, int row, int col);
};


// leetcode 542 --- 01 Matrix --- medium
// 广度优先搜索
vector<vector<int>> Solution_Leetcode542::updateMatrix(vector<vector<int>>& matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (matrix[i][j] == 1)
            {
                matrix[i][j] = BFS(matrix, i, j);
            }
        }
    }
    return matrix;
}

int Solution_Leetcode542::BFS(vector<vector<int>>& matrix, int row, int col)
{
    queue<pair<int, int>> pos;
    pair<int, int>cur_pos = make_pair(row, col);
    pos.push(cur_pos);

    int step = 0;
    vector<pair<int, int>> surround = { {0,1},{0,-1},{1,0},{-1,0} };

    set<pair<int, int>> visited;
    while (! pos.empty())
    {
        int len = pos.size();
        step++;
        for (int size = 0; size < len; ++size)
        {
            pair<int, int>& first_node = pos.front();
            visited.insert(first_node);
            for (int i = 0; i < surround.size(); ++i)
            {
                pair<int, int> temp = make_pair(first_node.first + surround[i].first, first_node.second + surround[i].second);

                // 校验是否访问或者超界
                if (temp.first < 0 || temp.first >= matrix.size() || temp.second < 0 || temp.second >= matrix[0].size() || visited.find(temp) != visited.end())
                {
                    continue;
                }
                if (matrix[temp.first][temp.second] == 0)
                {
                    return step;
                }
                else
                {
                    pos.push(temp);
                }
            }
            pos.pop();
        }
    }
    return step;
}