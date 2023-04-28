#include <bits/stdc++.h>
using namespace std;

string a = "aeiou", b = "bcdfghjklmnpqrstvwxyz", c;
vector<pair<string, bool>> v;
int main()
{
    while (true)
    {
        cin >> c;
        if (c == "end")
            break;
        int acnt = 0, bcnt = 0;
        bool check1 = false, check2 = true, check3 = true;
        char first = ' ';
        for (auto i : a)
        {
            if (c.find(i) != string::npos)
            {
                check1 = true;
            }
        }
        if (!check1)
        {
            v.push_back({c, false});
            continue;
        }
        for (auto i : c)
        {
            if (a.find(i) != string::npos)
            {
                acnt++;
                bcnt = 0;
            }
            else if (b.find(i) != string::npos)
            {
                bcnt++;
                acnt = 0;
            }
            if (acnt >= 3 || bcnt >= 3)
            {
                check3 = false;
                break;
            }
        }
        if (!check3)
        {
            v.push_back({c, false});
            continue;
}
            for (auto i : c)
            {
                if (i == first)
                {
                    if (i != 'e' && i != 'o')
                    {
                        check2 = false;
                        break;
                    }
                }
                else
                    first = i;
            }
        
        if (!check2)
        {
            v.push_back({c, false});
            continue;
        }

        v.push_back({c, true});
    }

    for (auto i : v)
    {
        if (i.second)
            cout << "<" << i.first << "> "
                 << "is acceptable." << '\n';
        else
            cout << "<" << i.first << "> "
                 << "is not acceptable." << '\n';
    }

    return 0;
}


