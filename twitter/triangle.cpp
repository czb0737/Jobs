#include <iostream>

using namespace std;

typedef pair<int, int> Point;

int dist(Point p1, Point p2);
bool triangle(Point p1, Point p2, Point p3);
bool triangle2(int len1, int len2, int len3);

bool triangle2(int len1, int len2, int len3)
{
    return (len1 == len2) + (len1 == len3) + (len2 + len3) > 0 && len1 + len2 > len3;
}

int dist(Point p1, Point p2)
{
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return dx * dx + dy * dy;
}

bool triangle(Point p1, Point p2, Point p3)
{
    int dist1 = dist(p1, p2);
    int dist2 = dist(p1, p3);
    int dist3 = dist(p2, p3);
    return (dist1 == dist2) + (dist1 == dist3) + (dist2 == dist3) > 0 && dist1 + dist2 > dist3;
}

int main(int argc, char **argv)
{
    cout << triangle(make_pair(0, 0), make_pair(4, 5), make_pair(5, 7)) << endl;
}