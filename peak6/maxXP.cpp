/*************************************************************************
	> File Name: maxXP.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/06/2017 Sat 11:48:49
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <fstream>

using namespace std;

double maxXP(vector<vector<long>> &board, int x, int y, int balls);
double getDist(int x1, int y1, int x2, int y2);

double maxXP(vector<vector<long>> &board, int x, int y, int balls)
{
    double result = 0;
    priority_queue<double> pq;
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            if (board[i][j] == 0)   continue;
            double cost = getDist(x, y, j, i) + log10(board[i][j]);
            pq.push(board[i][j] / cost);
        }
    }
    while (!pq.empty() && balls--)
    {
        result += pq.top();
        pq.pop();
    }
    return (double)long(result * 1000) / 1000;
}

double getDist(int x1, int y1, int x2, int y2)
{
    int dx = x1 - x2;
    int dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main(int argc, char **argv)
{
    ifstream in;
    in.open(string(argv[1]));
    int tmp = 0, x = 0, y = 0, balls = 0, h = 0, w = 0;

    in >> tmp;
    in >> x >> y;
    in >> balls;
    in >> h >> w;

    vector<vector<long>> board(h, vector<long>(w));

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            in >> board[i][j];
    cout << maxXP(board, x, y, balls) << endl;
    in.close();
}