/*************************************************************************
	> File Name: numOfCountry.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/13/2017 Wed 17:53:42
 ************************************************************************/

/**
 * 数国家，input一个二维数组，每个位置有一个颜色，相连的相同颜色块就算同一国家，本质是number of island
 */

#include <iostream>
#include <vector>

using namespace std;

int numOfCountry(vector<vector<int>> &board);
void dfs(vector<vector<int>> &board, int x, int y, int color);

int numOfCountry(vector<vector<int>> &board)
{
    int result = 0;
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            if (board[i][j] != -1)
            {
                ++result;
                dfs(board, i, j, board[i][j]);
            }
        }
    }
    return result;
}

void dfs(vector<vector<int>> &board, int x, int y, int color)
{
    if (x < 0 || x >= board.size() || y < 0 || y > board[0].size() || board[x][y] != color)
        return;
    board[x][y] = -1;
    dfs(board, x - 1, y, color);
    dfs(board, x, y - 1, color);
    dfs(board, x + 1, y, color);
    dfs(board, x, y + 1, color);
}

int main(int argc, char **argv)
{
    vector<vector<int>> board = {
        {1, 1, 1, 2}, 
        {3, 1, 2, 2},
        {3, 3, 3, 1},
        {0, 0, 1, 1}
    };
    cout << numOfCountry(board) << endl;
}