/*************************************************************************
	> File Name: Dictionary.h
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 08/29/2017 Tue 12:29:32
 ************************************************************************/

 #ifndef DICTIONARY_H
 #define DICTIONARY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Dictionary
{
private:

	unordered_map<string, string> dict;

	pair<string, string> split(string &s, char sep);
	bool valid(string &s, int start, int end, bool lb);
	void replaceAll(string &s, string replace_from, string replace_to);

public:

	Dictionary();
	void buildDict(string file_name);
	void displayDict();
	string replace(string &s);
};

#endif
