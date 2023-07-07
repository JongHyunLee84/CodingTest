#include <bits/stdc++.h>
using namespace std;

int A; 
string B;
int main()
{
    cin >> A >> B;
    cout << A * (B[2] - '0') << ' ' << A * (B[1] - '0') << ' ' << A * (B[0] - '0') << ' ' << A * stoi(B);

    return 0;
}
