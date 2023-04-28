#include <bits/stdc++.h>
using namespace std;
string s;

bool check(string s)
{
    stack<char> q;
    for (auto i : s)
    {
        if (i == '(')
        {
            q.push(i);
        }
        if (i == '[')
        {
            q.push(i);
        }
        if (i == ')')
        {
            if (q.size() == 0 || q.top() == '[')
                return false;
            else
                q.pop();
        }
        if (i == ']')
        {
            if (q.size() == 0 || q.top() == '(')
                return false;
            else
                q.pop();
        }
    }
    if (q.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    while (true)
    {
        getline(cin, s);
        if (s == ".")
            break;
        if (check(s))
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
    return 0;
}