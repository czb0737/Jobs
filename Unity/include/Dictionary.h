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
	// Dictionary set up by params.txt
	unordered_map<string, string> dict;

	// Split a string into two parts according to character 'sep'
	pair<string, string> split(string &s, char sep);
	// Find out if a string can match regular expression "\w+"
	bool valid(string &s, int start, int end, bool lb);
	// Replace a specific substring to another string.
	void replaceAll(string &s, string replace_from, string replace_to);

public:
	// Constructor of class Dictionary
	Dictionary();
	// Build dictionary using params.txt
	void buildDict(string file_name);
	// Replace strings that are in the dictionary
	string replace(string &s);
};

#endif
