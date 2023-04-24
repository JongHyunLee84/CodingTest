#include <bits/stdc++.h>
using namespace std;

int a, b, c, ret[101], sum;
vector<vector<int>> vt;

int main()
{
    cin >> a >> b >> c;
    for(int i = 0; i <=100; i++) ret[i] = 0;
    for (int i = 0; i <= 2; i++)
    {
        int in, out;
        cin >> in >> out;
        vector<int> v(101);
        for (int j = in; j < out; j++)
        {
            v.insert(v.begin() + j, 1);
        }
        vt.push_back(v);
    }
    for(auto i : vt) {
        for(int j = 0; j <= 100; j++) {
            if (i[j] == 1) {
                ret[j] += 1;
            }
        }
    }
    for(int i : ret) {
        if(i == 1) {
            sum += a;
        } else if(i == 2) {
            sum += b * 2;
        } else if(i == 3) {
            sum += c * 3;
        }
    }
    cout << sum << '\n';
    return 0;
}