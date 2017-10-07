/*************************************************************************
	> File Name: main.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 09/13/2017 Wed 23:25:41
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "../include/PhoneKeypadAlias.h"

using namespace std;

void display(vector<string> vs);

int main(int argc, char **argv)
{
    vector<string> dictionary = {"adg", "adh", "adi", "aeg", "aeh", "aei", 
        "afg", "afh", "afi", "bdg", "bdh", "bdi", "beg", "beh", "bei", 
        "bfg", "abfh", "bfihl", "scdg", "cfsdh", "casdfasdfdi", "cgheueg", 
        "cfhjweh", "cdfahajsdfei", "chemnfg", "cdfhfh", "cfi", "aigftfh"
    };
    PhoneKeypadAlias dict(dictionary);
    // Test 1
    cout << "Test 1: Alias are found in the dictionary." << endl;
    string word = "cfh";
    display(dict.getAlias(word));
    cout << endl;
    
    // Test 2
    cout << "Test 2: Alias is not found in the dictionary." << endl;
    word = "cfhz";
    display(dict.getAlias(word));
    cout << endl;
    
    // Test 3
    cout << "Test 3: Try to find alias of empty word." << endl;
    word = "";
    display(dict.getAlias(word));
    cout << endl;

    // Test 4
    cout << "Test 4: Another test that alias are found in the dictionary." << endl;
    word = "bhhevei";
    display(dict.getAlias(word));
}

void display(vector<string> vs)
{
    if (vs.empty())
    {
        cout << "No word found in the dictionary!" << endl;
        return;
    }
    cout << "Words are found as following: " << endl;
    for (auto &s : vs)
        cout << s << " ";
    cout << endl;
}