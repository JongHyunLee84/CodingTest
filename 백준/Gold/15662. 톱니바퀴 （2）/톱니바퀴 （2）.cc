#include <bits/stdc++.h>
using namespace std;

int t, k, ret, num, dir;
vector<vector<int>> wheels;
string s;
void rotate_left(int n, int d){
    if(n < 0)return;
    if(n - 1 >= 0 && wheels[n][6] != wheels[n-1][2]){
        rotate_left(n-1, d * -1);
    }
        if(d == 1)rotate(wheels[n].rbegin(), wheels[n].rbegin() + 1, wheels[n].rend());
        else rotate(wheels[n].begin(), wheels[n].begin() + 1, wheels[n].end());
}
void rotate_right(int n, int d){
    if(n >= t)return;
    if(n + 1 < t && wheels[n][2] != wheels[n+1][6]){
        rotate_right(n+1, d * -1);
    }
        if(d == 1)rotate(wheels[n].rbegin(), wheels[n].rbegin() + 1, wheels[n].rend());
        else rotate(wheels[n].begin(), wheels[n].begin() + 1, wheels[n].end());
}


int main() {
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> s;
        vector<int> v;
        for(char j : s)v.push_back(j-'0');
        wheels.push_back(v);
    }
    cin >> k;
    for(int i=0; i<k; i++){
        cin >> num >> dir;
        num--;
        if(num - 1 >= 0 && wheels[num][6] != wheels[num-1][2]){
        rotate_left(num-1, dir * -1);
        }
        if(num + 1 < t && wheels[num][2] != wheels[num+1][6]){
        rotate_right(num+1, dir * -1);
    }
        if(dir == 1)rotate(wheels[num].rbegin(), wheels[num].rbegin() + 1, wheels[num].rend());
        else rotate(wheels[num].begin(), wheels[num].begin() + 1, wheels[num].end());
    }
    for(int i=0; i<t; i++){
        if(wheels[i][0] == 1)ret++;
    }
    cout << ret << '\n';
    return 0;
}