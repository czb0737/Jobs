/*************************************************************************
	> File Name: hackingTime.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 08/26/2017 Sat 10:40:31
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void hackingTime(string &text);
vector<int> findKey(string &enc, string &dec, int count);
int findShortestKey(vector<int> &key);
bool compareVector(vector<int> &v, int s1, int s2, int len);

void hackingTime(string &text)
{
    int index = text.find_last_of("-");
    int count = 0;
    for (int i = 0; i < index; ++i)
        if (text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'a' && text[i] <= 'z')
            ++count;
    string enc = text.substr(index + 1);
    string dec = "Your friend, Alice";
    vector<int> key = findKey(enc, dec, count);
    int key_idx = 0, key_size = key.size();
    for (int i = 0; i < text.size(); ++i)
    {
        if (text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'a' && text[i] <= 'z')
        {
            char ch = text[i] > 'Z' ? 'a' : 'A';
            text[i] = (text[i] - key[key_idx] - ch + 26) % 26 + ch;
            key_idx = (key_idx + 1) % key_size;
        }
    }
}

vector<int> findKey(string &enc, string &dec, int count)
{
    vector<int> key;
    for (int i = 0; i < enc.size(); ++i)
        if (enc[i] >= 'A' && enc[i] <= 'Z' || enc[i] >= 'a' && enc[i] <= 'z')
            key.push_back((enc[i] - dec[i] + 26) % 26);
    int len = findShortestKey(key);

    // key.resize(len);
    int offset = len - count % len;
    key.assign(key.begin() + offset, key.begin() + len + offset);
    return key;
}

int findShortestKey(vector<int> &key)
{
    int size = key.size();
    for (int i = 1; i < size; ++i)
    {
        for (int j = i; j < size; j += i)
        {
            if (!compareVector(key, 0, j, min(i, size - j)))
                break;
            if (size - j <= i)
                return i;
        }
    }
    return size;
}

bool compareVector(vector<int> &v, int s1, int s2, int len)
{
    for (int i = 0; i < len; ++i)
        if (v[s1 + i] != v[s2 + i])
            return false;
    return true;
}

int main(int argc, char **argv)
{
    string enc = "Otjfvknou kskgnl, K mbxg iurtsvcnb ksgq hoz atv. Vje xcxtyqrl vt ujg smewfv vrmcxvtg rwqr ju vhm ytsf elwepuqyez. -Atvt hrqgse, Cnikg";
    string dec = "Your friend, Alice";
    hackingTime(enc);
    cout << enc << endl;
}