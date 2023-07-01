#include <bits/stdc++.h>
using namespace std;

int a[100004], temp, i, dp[5][5][100004];

int calculate(int lo, int de){
    if(lo == de)return 1;
    if(lo == 0){
        return 2;
    }else if(lo == 2){
        if(de == 1 || de == 3)return 3;
        else return 4;
    }else if(lo == 3){
        if(de == 2 || de == 4)return 3;
        else return 4;
    }else if(lo == 4){
        if(de == 1 || de == 3)return 3;
        else return 4;
    }else if(lo == 1){
        if(de == 2 || de == 4)return 3;
        else return 4;
    }
    return 0;
}

int go(int left, int right, int index) {
    if(index == i)return 0;
    int &ret = dp[left][right][index];
    if(ret != -1)return ret;
    ret = min(go(a[index], right, index+1) + calculate(left,a[index]), go(left, a[index], index+1) + calculate(right, a[index]) );
    return ret;
}

int main()
{
    while(1){
        cin >> temp;
        if(temp == 0)break;
        else a[i] = temp;
        i++;
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0,0,0) << '\n';
    return 0;
}
