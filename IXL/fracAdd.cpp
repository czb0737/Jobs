#include <iostream>
#include <string>
#include <vector>

using namespace std;

string fracAdd(string &s);
void add(pair<long, long> &p, int n, int d);
long gcd(long a, long b);

int main(int argc, char *argv[])
{
    string s = string(argv[1]);
    cout << fracAdd(s) << endl;
}

string fracAdd(string &s)
{
    if (s.empty())  return "";
    int num = isdigit(s[0]) ? s[0] - '0' : 0;
    vector<int> n, d;
    for (int i = 1; i < s.size(); ++i)
    {
        char ch = s[i];
        if (isdigit(ch))
            num = num * 10 + ch - '0';
        else
        {
            if (ch == '+')  d.push_back(num);
            else    n.push_back(num);
            num = 0;
        }
    }
    d.push_back(num);

    pair<long, long> p = make_pair(0, 1);
    for (int i = 0; i < n.size(); ++i)
        add(p, n[i], d[i]);

    return to_string(p.first) + "/" + to_string(p.second);
}

void add(pair<long, long> &p, int n, int d)
{
    long num = p.first * d + n * p.second;
    long den = p.second * d;
    long res = gcd(num, den);
    p.first = num / res;
    p.second = den / res;
}

long gcd(long a, long b)
{
    if (a == 0) return b;
    return gcd(b % a, a);
}