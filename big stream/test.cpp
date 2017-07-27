#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef unsigned char byte;

template <class T>
vector<byte> toByte(const T &t)
{
    cout << "Origin: " << t << endl;
    int size = sizeof(t);
    vector<byte> v(size);
    byte *ptr = (byte *)&t;
    copy(ptr, ptr + size, v.begin());
    return v;
}

vector<byte> toByte(const char *str)
{
    cout << "char *: " << str << endl;
    vector<byte> v(str, str + strlen(str));
    return v;
}

vector<byte> toByte(const string &s)
{
    cout << "string: " << s << endl;
    vector<byte> v(s.begin(), s.end());
    return v;
}

int main()
{
    int test = 1;
    test = (test << 8) + 1;
    test = (test << 8) + 3;
    test = (test << 8) + 5;

    const char *str = "abcdefg";
    string s("abcdefg");

    vector<byte> v1 = toByte(test);
    vector<byte> v2 = toByte(str);
    vector<byte> v3 = toByte(s);
    // for (int i = 0; i < v.size(); ++i)
    //     cout << int(v[i]) << endl;
}