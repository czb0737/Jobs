#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int minGenMutation(string start, string end, vector<string>& bank);

int minGenMutation(string start, string end, vector<string>& bank) 
{
    unordered_set<string> dict(bank.begin(), bank.end());
    if (dict.find(end) == dict.end())   return -1;
    unordered_set<string> sset, eset, *uset1, *uset2;
    sset.insert(start);
    eset.insert(end);
    int result = 0;
    
    while (!sset.empty() && !eset.empty())
    {
        if (sset.size() <= eset.size())
            uset1 = &sset, uset2 = &eset;
        else    uset1 = &eset, uset2 = &sset;
        ++result;
        unordered_set<string> tmp;
        for (const string &ss : *uset1)
        {
            for (int i = 0; i < ss.size(); ++i)
            {
                string s = ss;
                for (char ch : string("ACGT"))
                {
                    s[i] = ch;
                    if (uset2->find(s) != uset2->end())   return result;
                    if (dict.find(s) != dict.end())
                    {
                        tmp.insert(s);
                        dict.erase(s);
                    }
                }
            }
        }
        *uset1 = tmp;
    }
    return -1;
}

int main(int argc, char **argv)
{
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    string start = "AACCGGTT", end = "AAACGGTA";
    cout << minGenMutation(start, end, bank) << endl;
}