#include <bits/stdc++.h>
using namespace std;

int n;
string p, s;

int main()
{
    cin >> n >> p;
    int star = p.find('*');
    string pre = p.substr(0, star);
    string suf = p.substr(star + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (pre.size() + suf.size() > s.size())
        {
            cout << "NE\n";
        }
        else
        {
            if (pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size()))
                cout << "DA\n";
            else
                cout << "NE\n";
        }
    }
    return 0;
}
