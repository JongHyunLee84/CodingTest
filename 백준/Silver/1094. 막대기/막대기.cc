#include <bits/stdc++.h>
using namespace std;
int n, ret = 0;
int main(){ 
	cin >> n; 
	while(n != 0){
        if(n & 1) ret++; 
        n /= 2;
	}
	cout << ret << '\n';
    return 0;
}