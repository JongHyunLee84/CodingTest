#include <bits/stdc++.h>
using namespace std;

int N, cnt;
string s;
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        stack<char> st;
        for (auto i : s)
        {
            if (st.size() && st.top() == i)
                st.pop();
            else
                st.push(i);
        }
        if (st.size() == 0)
            cnt++;
    }
    cout << cnt << '\n';

    return 0;
}