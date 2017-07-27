#include <iostream>
#include <string>
#include "multikeyHash.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    auto func = [](const auto & ... tp) { return make_tuple(tp...); };

    // First test
    MultikeyHash<string, const char *, int, double> mkh1;
    cout << "First test: [<string, const char *, int, double>(string(\"abcd\"), \"abcd\", 1, 1.5)]" << endl;
    cout << "1st apply: hash code is " << mkh1.apply(func, string("abcd"), "abcd", 1, 1.5) << endl;
    cout << "2nd apply: hash code is " << mkh1.apply(func, string("abcd"), "abcd", 1, 1.5) << endl;
    cout << endl;
    
    // Second test
    MultikeyHash<string> mkh2;
    cout << "Second test: [<string>(string(\"abcd\")]" << endl;
    cout << "1st apply: hash code is " << mkh2.apply(func, string("abcd")) << endl;
    cout << "2nd apply: hash code is " << mkh2.apply(func, string("abcd")) << endl;
    cout << endl;
    
    // Third test
    MultikeyHash<int, long, double, float, int, int, int, int> mkh3;
    cout << "Third test: [<int, long, double, float, int, int, int, int>(1, 2, 2.5, 3.5, 1, 1, 1, 1)]" << endl;
    cout << "1st apply: hash code is " << mkh3.apply(func, 1, 2, 2.5, 3.5, 1, 1, 1, 1) << endl;
    cout << "2nd apply: hash code is " << mkh3.apply(func, 1, 2, 2.5, 3.5, 1, 1, 1, 1) << endl;
}