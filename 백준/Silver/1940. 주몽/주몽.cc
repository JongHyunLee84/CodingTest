#include <bits/stdc++.h>
using namespace std;

int N, M, n, ret;
vector<int> v;

int main()
{
    cin >> N >> M;
    if (M > 200000)
    {
        cout << 0 << "\n";
        exit(0);
    }

    for (int i = 0; i < N; i++)
    {
        cin >> n;
        v.push_back(n);
    }
    for (int i : v)
    {
        if (find(v.begin(), v.end(), M - i) != v.end())
        {
            ret++;
        }
    }
    cout << ret / 2 << '\n';
    return 0;
}