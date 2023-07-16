/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

string s;
int a, n, ret;

char cal(int temp) {
    if(temp >= 0 && temp <= 9){
        return temp + '0';
    }
    else return (char) (temp - 10 + 'A');
}

int main()
{
    cin >> a >> n;
    while(a > 0){
        s += cal(a%n);
        a /= n;
    }
    reverse(s.begin(), s.end());
    if(s[0] == '0'){
        for(int i=1; i<s.size(); i++)cout<<s[i];
    }else cout << s << '\n';
    return 0;
}
