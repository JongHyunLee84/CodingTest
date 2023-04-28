#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
        ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t = 0, two = 0, five = 0;
        cin >> t;
        for (int j = 2; j <= t; j *= 2)
        {
            two += t / j;
        }
        for (int j = 5; j <= t; j *= 5)
        {
            five += t / j;
        }
        cout << min(two, five) << '\n';
    }
    return 0;
}