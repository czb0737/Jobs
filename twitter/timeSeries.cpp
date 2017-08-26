/*************************************************************************
	> File Name: timeSeries.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 08/26/2017 Sat 11:27:54
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

vector<string> timeSeries(string file_name);
vector<string> split(string str, char sep);
void trim(string &s);

vector<string> timeSeries(string file_name)
{
	unordered_map<int, int> umap;
	vector<pair<int, unordered_map<string, int>>> logs;
	ifstream file(file_name);
	string s;
	getline(file, s, '\n');
	vector<string> s_to_e = split(s, ',');
	int start = stoi(s_to_e[0]) * 100 + stoi(s_to_e[0].substr(5, 2));
	int end = stoi(s_to_e[1]) * 100 + stoi(s_to_e[1].substr(5, 2));
	getline(file, s, '\n');
	while (getline(file, s, '\n'))
	{
		// Handle the time
		vector<string> vs = split(s, ',');
		int t = stoi(vs[0]) * 100 + stoi(vs[0].substr(5, 2));
		if (t < start || t > end)	continue;
		// Handle actions and number
		if (umap.find(t) == umap.end())
		{
			umap.insert(make_pair(t, logs.size()));
			logs.emplace_back(make_pair(t, unordered_map<string, int>()));
		}
		logs[umap[t]].second[vs[1]] += stoi(vs[2]);
	}
	vector<string> result;
	for (auto &vp : logs)
	{
		stringstream ss;
		ss << vp.first / 100 << '-' << setw(2) << setfill('0') << vp.first % 100;
		for (auto &p : vp.second)
			ss << ", " << p.first << ", " << p.second;
		result.push_back(ss.str());
	}
	return result;
}

vector<string> split(string str, char sep)
{
	stringstream ss(str);
	vector<string> result;
	string s;
	while (getline(ss, s, sep))
	{
		trim(s);
		result.push_back(s);
	}
	return result;
}

void trim(string &s)
{
	int ptr1 = 0, ptr2 = s.size() - 1;
	while (ptr1 <= ptr2 && s[ptr1] == ' ')	++ptr1;
	while (ptr2 >= ptr1 && s[ptr2] == ' ')	--ptr2;
	if (ptr1 > ptr2)
	{
		s.clear();
		return;
	}
	s.assign(s.begin() + ptr1, s.begin() + ptr2 + 1);
}

int main(int argc, char **argv)
{
	vector<string> result = timeSeries(string(argv[1]));
	for (auto &s : result)
		cout << s << endl;
}