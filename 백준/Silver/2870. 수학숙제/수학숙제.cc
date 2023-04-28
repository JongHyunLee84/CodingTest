#include <bits/stdc++.h>
using namespace std;
int n;
string s, temp = "";
vector<string> v;

bool compare(string a, string b)
{
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (auto i : s)
        {
            if (isdigit(i))
            {
                temp += i;
            }
            else
            {
                if (temp != "")
                {
                    v.push_back(temp);
                    temp = "";
                }
            }
            if (temp.size() == 2 && temp[0] == '0')
                temp = temp[1];
        }
        if (temp != "")
        {
            v.push_back(temp);
            temp = "";
        }
    }

    sort(v.begin(), v.end(), compare);
    for (string i : v)
        cout << i << '\n';
    return 0;
}
