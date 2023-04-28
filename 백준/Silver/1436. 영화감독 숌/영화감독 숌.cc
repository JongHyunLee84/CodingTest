#include <bits/stdc++.h>
using namespace std;
int six = 666, num, cnt = 1;

int main()
{
    cin >> num;
    while (num != cnt)
    {
        six++;
        string s = to_string(six);
        if (s.find("666") != string::npos)
        {
            cnt++;
        }
    }
    cout << six;
    return 0;
}