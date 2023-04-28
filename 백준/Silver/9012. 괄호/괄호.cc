#include <bits/stdc++.h>
using namespace std;
int n, cnt;
string s, ret;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (auto i : s)
        {
            if (i == '(')
                cnt++;
            else
            {
                if (cnt == 0)
                {
                    ret = "NO";
                    break;
                }
                cnt--;
            }
        }
        if (ret == "")
        {
            if (cnt != 0)
            {
                ret = "NO";
            }
            else
                ret = "YES";
        }
        cout << ret << '\n';
        ret = "";
        cnt = 0;
    }
    return 0;
}