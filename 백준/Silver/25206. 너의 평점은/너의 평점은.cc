#include <bits/stdc++.h>
using namespace std;

string s, a, c;
int i, n;
double b, ret, sum;

double calcul(string gpa) {
if("A+" == gpa)return 4.5;
if("A0" == gpa)return 4.0;
if("B+" == gpa)return 3.5;
if("B0" == gpa)return 3.0;
if("C+" == gpa)return 2.5;
if("C0" == gpa)return 2.0;
if("D+" == gpa)return 1.5;
if("D0" == gpa)return 1.0;
if("F" == gpa)return 0.0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=0; i<20; i++){
        cin >> a >> b >> c;
        if(c == "P")continue;
        sum += b;
        ret += b * calcul(c);
    }
    cout << ret / sum << '\n';
    return 0;
}
