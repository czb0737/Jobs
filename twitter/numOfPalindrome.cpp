#include <iostream>
#include <string>

using namespace std;

int numOfPalindrome(string &s);

int numOfPalindrome(string &s)
{
    int count = 0;
    int ptr1 = 0, ptr2 = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        // Find the substring has the same character
        ptr1 = i - 1, ptr2 = i + 1;
        while (ptr1 >= 0 && s[ptr1] == s[i])    --ptr1;
        while (ptr2 < s.size() && s[ptr2] == s[i])  ++ptr2;
        // Calculate the number of palindrome in the substring with same character
        int len = ptr2 - ptr1 - 1;
        count += len * (len + 1) / 2;
        // Let i point to the end of the substring with same character
        i = ptr2 - 1;
        // Find palindrome with different characters
        while (ptr1 >= 0 && ptr2 < s.size() && s[ptr1] == s[ptr2])
        {
            ++count;
            --ptr1;
            ++ptr2;
        }
    }
    return count;
}

int main(int argc, char **argv)
{
    string s(argv[1]);
    cout << numOfPalindrome(s) << endl;
}