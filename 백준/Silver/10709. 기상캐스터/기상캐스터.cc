#include <bits/stdc++.h>
using namespace std;
int a[104][104], ret[104][104], h, w;
string s;
int main()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        cin >> s;
        for (int j = 0; j < w; j++)
        {
            if (s[j] == 'c')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = w - 1; j >= 0; j--)
        {
            int cnt = 1;
            if (a[i][j])
                ret[i][j] = 0;
            else
            {
                for (int k = j - 1; k >= 0; k--)
                {
                    if (a[i][k] == 1)
                    {
                        ret[i][j] = cnt;
                        break;
                    }
                    else
                    {
                        cnt++;
                    }
                }
                if (ret[i][j] == 0)
                    ret[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << ret[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
