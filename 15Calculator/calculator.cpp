#include <iostream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

int cal(const int &n1, const int &n2, const char &op)
{
    switch(op)
    {
    case '+':
        return n1 + n2;
    case '-':
        return n1 - n2;
    case '*':
        return n1 * n2;
    case '/':
        return n1 / n2;
    case '^':
        return pow(n1, n2);
    }
}

int calculator(string s)
{
    if (s.empty())  return 0;
    stack<int> n_st;
    stack<char> op_st;
    size_t cur = 0;
    size_t offset = 0;
    while (s[cur] == ' ')   ++cur;
    n_st.push(stoi(s.substr(cur), &offset));
    cur += offset;

    while (cur < s.length())
    {
        if (s[cur] == ' ')
        {
            cur++;
            continue;
        }
        if (isdigit(s[cur]))  
        {
            int n = stoi(s.substr(cur), &offset);
            cur += offset;
            if (!op_st.empty() && (op_st.top() == '*' || op_st.top() == '/' || op_st.top() == '^'))
            {
                n = cal(n_st.top(), n, op_st.top());
                n_st.pop(), op_st.pop();
            }
            n_st.push(n);
        }
        else
        {
            if (s[cur] == '(')
            {
                int tmp_idx = ++cur;
                int left = 1;
                while (left > 0)
                {
                    if (s[cur] == '(')  ++left;
                    if (s[cur] == ')')  --left;
                    ++cur;
                }
                int num = calculator(s.substr(tmp_idx, cur - tmp_idx - 1));
                n_st.push(num);
            }
            else
                op_st.push(s[cur++]);
        }
    }

    stack<char> op_st2;
    while (!op_st.empty())
    {
        op_st2.push(op_st.top());   
        op_st.pop();
    }
    stack<int> n_st2;
    while (!n_st.empty())
    {
        n_st2.push(n_st.top());   
        n_st.pop();
    }

    while (!op_st2.empty())
    {
        int n1 = n_st2.top();    n_st2.pop();
        int n2 = n_st2.top();    n_st2.pop();
        n_st2.push(cal(n1, n2, op_st2.top()));
        op_st2.pop();
    }
    return n_st2.top();
}

int calculate(string s)
{
    stack<int> stk;
    char sign = '+';
    int num = 0;
    
    for(int i = 0; i <= s.length(); ++i)
    {
        char c = i == s.length() ? ' ' : s[i];
        if (i == s.length() || c == '+' || c == '-' || c == '*' || c == '/')
        {
            int tmp = 0;
            switch(sign)
            {
                case '+':
                    stk.push(num);
                    break;
                case '-':
                    stk.push(-num);
                    break;
                case '*':
                    tmp = stk.top();
                    stk.pop();
                    stk.push(tmp * num);
                    break;
                case '/':
                    tmp = stk.top();
                    stk.pop();
                    stk.push(tmp / num);
                    break;
            }
            sign = c;
            num = 0;
        }
        else if (isdigit(c))
            num = num * 10 + c - '0';
        else if (c == '(')
        {
            int idx = i + 1, remain = 1;
            while (remain > 0)
            {
                if (s[idx] == '(')    ++remain;
                else if (s[idx] == ')')   --remain;
                ++idx;
            }
            num = calculate(s.substr(i + 1, idx - i - 2));
            i = idx - 1;
        }
    }
    int result = 0;
    while (!stk.empty())
    {
        result += stk.top();
        stk.pop();
    }
    return result;
}

int main(int args, char *argv[])
{
    // string s(argv[1]);
    // cout << s << endl;
    string s("(3+2)*(3+2)");
    cout << s << "=" << calculate(s) << endl;
}