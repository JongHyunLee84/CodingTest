#include <bits/stdc++.h>
using namespace std;

int N, K, d, ret = -10000004;

int main()
{
    cin >> N >> K;
    int ar[N];
    for (int i = 0; i <= N; i++)
        ar[i] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> d;
        ar[i] = ar[i - 1] + d;
    }
    for (int i = K; i <= N; i++)
    {
        if (ar[i] - ar[i - K] >= ret)
        {
            ret = ar[i] - ar[i - K];
        }
    }
    cout << ret << '\n';
}