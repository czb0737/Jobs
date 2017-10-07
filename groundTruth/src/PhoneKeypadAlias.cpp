/*************************************************************************
	> File Name: PhoneKeypadAlias.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/13/2017 Wed 23:21:16
 ************************************************************************/

#include "../include/PhoneKeypadAlias.h"

// Mapping 26 letters to numbers
vector<int> PhoneKeypadAlias::nums = {
    2, 2, 2, 
    3, 3, 3, 
    4, 4, 4,
    5, 5, 5,
    6, 6, 6,
    7, 7, 7, 7,
    8, 8, 8,
    9, 9, 9, 9
};

// Convert a word to a series of numbers
string PhoneKeypadAlias::wordToNum(string &word)
{
    string s;
    for (auto &ch : word)
    {
        s.append(to_string(PhoneKeypadAlias::nums[ch - 'a']));
    }
    return s;
}

PhoneKeypadAlias::PhoneKeypadAlias(vector<string> &words)
{
    for (auto &word : words)
    {
        this->dict[wordToNum(word)].push_back(word);
    }
}

vector<string> PhoneKeypadAlias::getAlias(string word)
{
    string s = wordToNum(word);
    return this->dict[s];
}

PhoneKeypadAlias::~PhoneKeypadAlias() {}