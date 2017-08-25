#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> infoMask(vector<string> &vs);

vector<string> infoMask(vector<string> &vs)
{
    vector<string> result;
    for (string &s : vs)
    {
        string ss;
        if (s.front() == 'E')
        {
            int index = s.find("@");
            int i = 2;
            while (s[i] == ' ') ++i;
            ss.push_back(s[i]);
            ss.append("*****").append(s.substr(index - 1));
        }
        else
        {
            bool digit = false;
            int size = s.size();
            for (int i = 2; i < size - 9; ++i)
            {
                if (s[i] == '+')    ss.push_back('+');
                else if (isdigit(s[i]))
                {
                    ss.push_back('*');
                    digit = true;
                }
                else if (s[i] == '(' && digit)
                    ss.push_back('-');
            }
            ss.append("-***-").append(s.substr(size - 4));
        }
        result.push_back(ss);
        ss.clear();
    }
    return result;
}

int main(int argc, char **argv)
{
    vector<string> vs = {"E: safdfs@gmail.com", "P: +1(321)321-3241", "P: +12(342)423-7294", "P: 483 738 3821", "P: (342)321-3726"};
    auto vv = infoMask(vs);
    for (auto &s : vv)
        cout << s << endl;
}