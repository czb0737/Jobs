#ifndef _TO_BYTES_
#define _TO_BYTES_

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

typedef unsigned char byte;

template <class T>
vector<byte> toBytes(const T &t)
{
    cout << "Origin: " << t << endl;
    int size = sizeof(t);
    vector<byte> v(size);
    byte *ptr = (byte *)&t;
    copy(ptr, ptr + size, v.begin());
    return v;
}

vector<byte> toBytes(const char *str)
{
    cout << "char *: " << str << endl;
    vector<byte> v(str, str + strlen(str));
    return v;
}

vector<byte> toBytes(const string &s)
{
    cout << "string: " << s << endl;
    vector<byte> v(s.begin(), s.end());
    return v;
}

#endif