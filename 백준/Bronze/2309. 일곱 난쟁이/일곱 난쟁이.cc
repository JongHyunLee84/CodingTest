#include <bits/stdc++.h>
using namespace std;

int a[9], c;

int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
        c += a[i];
    }
    c -= 100;
    sort(a, a + 9);
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if ((a[i] + a[j]) == c)
            {
                for (int k : a)
                {
                    if (k == a[i] || k == a[j])
                    {
                        continue;
                    }
                    else
                    {
                        cout << k << '\n';
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}