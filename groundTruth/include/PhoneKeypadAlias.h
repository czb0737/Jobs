/*************************************************************************
	> File Name: PhoneKeypadAlias.h
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/13/2017 Wed 23:14:18
 ************************************************************************/

#ifndef PHONEKEYPADALIAS_H
#define PHONEKEYPADALIAS_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class PhoneKeypadAlias 
{
private:
    // Dictionary for getting alias
    unordered_map<string, vector<string>> dict;

    // Convert a word to a series of numbers
    string wordToNum(string &word);

public:
    // Mapping 26 letters to numbers
    static vector<int> nums;
    // Assume the dictionary is provided.
    // There is no duplicate word in the dictionary.
    // All the words are able to link to a number by the phone keypad mapping
    PhoneKeypadAlias(vector<string>& words);
    ~PhoneKeypadAlias();

    // The api will be called frequently.
    vector<string> getAlias(string word);
};

#endif