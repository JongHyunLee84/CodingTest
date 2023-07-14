#include <bits/stdc++.h>
using namespace std;

int n, ar[100][100], a, b, ret, sum;
string s;


int main()
{
    cin >> s >> b;
	for (int i=0; i<s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			sum = sum*b + (s[i] - '0');
		}
			else 
				sum = sum*b + (s[i] - 'A' + 10);
		}
	cout << sum << '\n';
    return 0;
}
