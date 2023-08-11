#include <bits/stdc++.h>
using namespace std;

int n, m, k, ar[54][54], temp[54][54], temp2[54][54], r, c, s, ret = 1e9;
vector<vector<int>> v;
vector<int> per;

void print() {
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << temp2[i][j] << ' ';
        }
        cout << '\n';
    }
}
void fill() {
        for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!temp2[i][j])temp2[i][j] = temp[i][j];
        }
    }
}

void rotate_(int r, int c, int s){
    pair<int,int> fir = {r-s-1, c-s-1}, sec = {r+s-1, c+s-1};
    while(fir.first < sec.first){
        // cout << fir.first << '.' << fir.second << ' ' << sec.first << '.' << sec.second << '\n';
        for(int i=fir.first; i<= sec.first; i++){
            for(int j=fir.second; j<=sec.second; j++){
                if(i == fir.first && j < sec.second)temp2[i][j+1] = temp[i][j];
                else if(i < sec.first && j == sec.second)temp2[i+1][j] = temp[i][j];
                else if(i == sec.first && j > fir.second)temp2[i][j-1] = temp[i][j];
                else if(i > fir.first && j == fir.second)temp2[i-1][j] = temp[i][j];
            }
        }
        fir.first++; fir.second++; sec.first--; sec.second--;
        // print();
        // cout << "--------" << '\n';
    }
    fill();
}



void count_() {
    int min_ = 1e9;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<m; j++){
            sum += temp[i][j];
        }
        min_ = min(min_, sum);
    }
    ret = min(ret, min_);
}



int main()
{
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> ar[i][j];
        }
    }
    for(int i=0; i<k; i++){
        per.push_back(i);
        cin >> r >> c >> s;
        vector<int> temp = {r,c,s};
        v.push_back(temp);
    }
    do {
        memcpy(temp, ar, sizeof(temp));
        for(int i : per){
            rotate_(v[i][0], v[i][1], v[i][2]);
            memcpy(temp, temp2, sizeof(temp));
            memset(temp2, 0, sizeof(temp2));
        }
        count_();
        // cout << "finish" << '\n';
    }while(next_permutation(per.begin(), per.end()));
    cout << ret << '\n';
    return 0;
}
