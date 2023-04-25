#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l, tl = 1;
int cnt = 1;

int main()
{
    while (cin >> l)
        while (true)
        {
            if (tl % l == 0)
            {
                cout << cnt << '\n';
                tl = 1; cnt = 1;
                break;
            }
            else
            {
                cnt++;
                tl = (tl * 10) + 1;
                tl = tl % l;
            }
        }

    return 0;
}
