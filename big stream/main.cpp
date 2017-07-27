#include <iostream>
#include <string>
#include "multikeyHash.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    // template <class ...Tpl>
    auto func = [](const auto & ... tp) { return make_tuple(tp...); };

    MultikeyHash<string, const char *, int, double> mkh;
    // First test
    cout << mkh.apply(func, string("abcd"), "abcd", 1, 1.5) << endl;
    cout << mkh.apply(func, string("abcd"), "abcd", 1, 1.5) << endl;
}