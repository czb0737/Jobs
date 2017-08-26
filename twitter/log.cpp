#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <time.h>
#include <memory.h>
#include <iomanip>

using namespace std;

string transferLog(string &s);

unordered_map<string, int> umap = {{"Jan", 1}, {"Feb", 2}, {"Mar", 3}, 
                                    {"Apr", 4}, {"May", 5}, {"Jun", 6},
                                    {"Jul", 7}, {"Aug", 8}, {"Sep", 9},
                                    {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};

string transferLog(string &s)
{
    int index1 = s.find("[");
    s[index1 + 3] = ' ';
    vector<int> v;
    int num = 0;
    int sign = 1;
    for (int i = index1 + 1; s[i] != '\"'; ++i)
    {
        char ch = s[i];
        if (ch == ' ')  continue;
        else if (isdigit(ch))
            num = num * 10 + ch - '0';
        else if (ch == '/' || ch == '+' || ch == ':' || ch == ']' || ch == '-')
        {
            if (ch == '+')  sign = -1;
            v.push_back(num);
            num = 0;
        }
    }

    struct tm *cur_t = new tm;
    memset(cur_t, 0, sizeof(struct tm));
    cur_t->tm_year = v[1] - 1900;
    cur_t->tm_mon = umap[s.substr(index1 + 4, 3)];
    cur_t->tm_mday = v[0];
    cur_t->tm_hour = v[2];
    cur_t->tm_min = v[3];
    cur_t->tm_sec = v[4];
    long ttt = (long) mktime(cur_t) + v[5] * 36;
    delete cur_t;
    cur_t = gmtime((time_t *)&ttt);
    ostringstream ss;
    ss << cur_t->tm_year + 1900 << '-' << setw(2) << setfill('0') << cur_t->tm_mon << '-' 
        << setw(2) << setfill('0') << cur_t->tm_mday << 'T' << setw(2) << setfill('0') 
        << cur_t->tm_hour << ":" << setw(2) << setfill('0') << cur_t->tm_min << " ";
    index1 = s.find("/", index1 + 27);
    int index2 = s.find_first_of("? ", index1);
    ss << s.substr(index1, index2 - index1);
    return ss.str();
}

int main(int argc, char **argv)
{
    vector<string> vs = {"10.10.10.10 - - [27/Sep/2016:05:31:23 +0000] \"GET /1.1/friendship/list.json?user_id=123 HTTP/1.1\" 500 563 19 \"Twitter-iPhone/6.63iOS/10.0.2 (Apple;iPhone7,2;;;;;1)\" 177.177.177.177",
        "10.10.10.10 - - [27/Sep/2016:05:31:23 +0800] \"GET /1.1/friendship/list.json?user_id=123 HTTP/1.1\" 500 563 19 \"Twitter-iPhone/6.63iOS/10.0.2 (Apple;iPhone7,2;;;;;1)\" 177.177.177.177",
        "10.10.10.10 - - [27/Sep/2016:05:31:23 -2000] \"GET /1.1/friendship/list.json?user_id=123 HTTP/1.1\" 500 563 19 \"Twitter-iPhone/6.63iOS/10.0.2 (Apple;iPhone7,2;;;;;1)\" 177.177.177.177"};
    for (string &s : vs)
        cout << transferLog(s) << endl;
}