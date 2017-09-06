/*************************************************************************
	> File Name: maxCP.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/06/2017 Sat 15:28:39
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <fstream>

using namespace std;

double maxCP(vector<vector<double>> &pokes, vector<double> &lvm, int ups);
double getCP(vector<double> &v, vector<double> &lvm, bool flag);

struct Comp
{
    bool operator()(const vector<double> &v1, const vector<double> &v2)
    {
        return v1[5] - v1[4] < v2[5] - v2[4];
    }
};

double maxCP(vector<vector<double>> &pokes, vector<double> &lvm, int ups)
{
    priority_queue<vector<double>, vector<vector<double>>, Comp> pq;
    for (auto &pok : pokes)
    {
        if (pok.back() == 40.0) continue;
        pok.back() = pok.back() * 2 - 2;
        pok.push_back(getCP(pok, lvm, false));
        pok.push_back(getCP(pok, lvm, true));
        pq.push(pok);
    }

    double result = 0.0;
    while (!pq.empty() && ups--)
    {
        auto v = pq.top();
        pq.pop();
        result += v[5] - v[4];
        if (++v[3] == 78)   continue;
        v[4] = v[5];
        v[5] = getCP(v, lvm, true);
        pq.push(v);
    }
    return (double)long(result * 100000000) / 100000000;
}

// v[0]: attack, v[1]: defence, v[2]: stamina, v[3]: level, v[4]: current CP, v[5]: next CP
double getCP(vector<double> &v, vector<double> &lvm, bool flag)
{
    return sqrt(v[1]) * sqrt(v[2]) * lvm[v[3] + flag] * lvm[v[3] + flag] / 10 * v[0];
}

int main(int argc, char **argv)
{
    ifstream in;
    in.open(string(argv[1]));
    int ups = 0, num_pokes = 0, tmp;
    in >> ups >> num_pokes >> tmp;
    vector<vector<double>> pokes(num_pokes, vector<double>(4));
    for (int i = 0; i < num_pokes; ++i)
    {
        in >> pokes[i][0] >> pokes[i][1] >> pokes[i][2] >> pokes[i][3];
    }
    in >> tmp;
    vector<double> lvm(tmp);
    for (int i = 0; i < tmp; ++i)
    {
        in >> lvm[i];
    }
    double d = maxCP(pokes, lvm, ups);
    cout.precision(10);
    cout << d << endl;

    in.close();
}