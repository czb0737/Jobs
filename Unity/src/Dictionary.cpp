/*************************************************************************
	> File Name: Dictionary.cpp
	> Author: czb
	> Mail: zhibinc.cs@gmail.com
	> Created Time: 08/29/2017 Tue 12:36:01
 ************************************************************************/

#include "../include/Dictionary.h"

/*
 * Constructor of class Dictionary
 */
Dictionary::Dictionary()
{
    // this->buildDict(file_name);
}

/*
 * Build dictionary using params.txt
 */
void Dictionary::buildDict(string file_name)
{
    // Key-value pair from params.txt
    unordered_map<string, string> &umap = this->dict;
    // Adjacent table for dictionary <from node, <in degree, to nodes>>
    unordered_map<string, pair<int, vector<string>>> adj;

    ifstream in;
    in.open(file_name);
    string s;
    while (getline(in, s, '\n'))
    {
        pair<string, string> pss = split(s, ':');
        umap.insert(pss);
        adj.insert(make_pair(pss.first, make_pair(0, vector<string>())));
    }
    // Close the file descriptor for params.txt
    in.close();
    
    // Build adjacent table
    for (auto &p : umap)
    {
        int idx = 0;
        string &s = p.second;
        while (idx < (int)s.size() && (int)string::npos != (idx = s.find("{{", idx)))
        {
            int r_idx = s.find("}}", idx + 2);
            if (r_idx == (int)string::npos)
            {
                break;
            }
            if (!valid(s, idx + 2, r_idx, true))
            {
                idx += 2;
                continue;
            }
            string tmp_s = s.substr(idx + 2, r_idx - idx - 2);
            if (umap.find(tmp_s) != umap.end())
            {
                adj[tmp_s].second.push_back(p.first);
                ++adj[p.first].first;
            }
            idx = r_idx + 2;
        }
    }
    
    // Topo-sort
    queue<string> q;
    int num_edge = 0;
    for (auto &p : adj)
    {
        // Find all node whose indegree is 0
        if (p.second.first == 0)
        {
            q.push(p.first);
        }
        num_edge += p.second.first;
    }

    while (!q.empty())
    {
        string ss = q.front();
        q.pop();
        for (auto &vs : adj[ss].second)
        {
            this->replaceAll(umap[vs], "{{" + ss + "}}", umap[ss]);
            if (--adj[vs].first == 0)
            {
                q.push(vs);
            }
            --num_edge;
        }
    }

    // Exit if there exist at least one circle
    if (num_edge > 0)
    {
        cerr << "There is at least one circular reference!" << endl;
        exit(1);
    }

    // Replace all "{{lb}}"
    for (auto &p : umap)
    {
        int idx = 0;
        while ((int)string::npos != (idx = p.second.find("{{lb}}", idx)))
        {
            p.second.erase(idx + 1, 5);
            ++idx;
        }
    }

    // Add "lb" to the dictionary
    this->dict.insert(make_pair("lb", "{"));
}

/*
 * Replace a specific substring to another string.
 */
void Dictionary::replaceAll(string &s, string replace_from, string replace_to)
{
    stringstream ss;
    int idx1 = 0, idx2 = 0;

    while ((int)string::npos != (idx2 = s.find(replace_from, idx1)))
    {
        ss << s.substr(idx1, idx2 - idx1) << replace_to;
        idx1 = idx2 + replace_from.size();
    }
    ss << s.substr(idx1, s.size() - idx1);

    s = ss.str();
}

/*
 * Find out if a string can match regular expression "\w+"
 */
bool Dictionary::valid(string &s, int start, int end, bool lb = true)
{
    if (start > end || (lb && s.substr(start, end - start).compare("lb") == 0))
    {
        return false;
    }
    for (int i = start; i < end; ++i)
    {
        const char &ch = s[i];
        if (!((ch >= 'A' && ch <= 'Z') 
            || (ch >= 'a' && ch <= 'z') 
            || (ch >= '0' && ch <= '9') 
            || ch == '_'))
        {
            return false;
        }
    }
    return true;
}

/*
 * Split a string into two parts according to character 'sep'
 */
pair<string, string> Dictionary::split(string &s, char sep = ':')
{
    int idx = s.find_first_of(':');
    if (idx == (int)string::npos || idx == 0 || idx == (int)s.size() - 1 || !valid(s, 0, idx))
    {
        cerr << "Format of params.txt is wrong" << endl;
        exit(1);
    }
    return make_pair(s.substr(0, idx), s.substr(idx + 1));
}

/*
 * Replace strings that are in the dictionary
 */
string Dictionary::replace(string &s)
{
    stringstream ss;
    int idx = 0, s_idx = 0;
    while (idx < (int)s.size() && (int)string::npos != (idx = s.find("{{", idx)))
    {
        int r_idx = s.find("}}", idx + 2);
        if (r_idx == (int)string::npos)
        {
            break;
        }
        if (!valid(s, idx + 2, r_idx, false))
        {
            idx += 2;
            continue;
        }
        string tmp_s = s.substr(idx + 2, r_idx - idx - 2);
        if (this->dict.find(tmp_s) == this->dict.end())
        {
            idx = r_idx + 2;
            continue;
        }
        ss << s.substr(s_idx, idx - s_idx) << this->dict[tmp_s];
        s_idx = idx = r_idx + 2;
    }
    ss << s.substr(s_idx, s.size() - s_idx);
    return ss.str();
}