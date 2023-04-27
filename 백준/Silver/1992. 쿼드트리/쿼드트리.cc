#include <bits/stdc++.h>
using namespace std;
int n, ar[64][64];

string go(int start_y, int start_x, int size)
{

    if (size == 1)
        return to_string(ar[start_y][start_x]);
    string ret;
    int whichNum = ar[start_y][start_x];
    for (int i = start_y; i < start_y + size; i++)
    {
        for (int j = start_x; j < start_x + size; j++)
        {
            if (whichNum != ar[i][j])
            {
                // cout << "4등분 시작 " << '\n';

                ret += "(";
                // cout << start_y << "." << start_x << '.' << size / 2 << '\n';
                ret += go(start_y, start_x, size / 2);
                // cout << start_y << "." << start_x + (size / 2) << '.' << size / 2 << '\n';
                ret += go(start_y, start_x + (size / 2), size / 2);
                // cout << start_y + (size / 2) << "." << start_x << '.' << size / 2 << '\n';
                ret += go(start_y + (size / 2), start_x, size / 2);
                // cout << start_y + (size / 2) << "." << start_x + (size / 2) << '.' << size / 2 << '\n';
                ret += go(start_y + (size / 2), start_x + (size / 2), size / 2);
                ret += ")";

                return ret;
            }
        }
    }
    return to_string(ar[start_y][start_x]);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%1d", &ar[i][j]);
        }
    }

    cout << go(0, 0, n);
    return 0;
}