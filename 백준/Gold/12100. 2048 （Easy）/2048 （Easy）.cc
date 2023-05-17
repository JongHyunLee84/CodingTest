#include <bits/stdc++.h>
using namespace std;
int n, ret, ar[24][24];

struct Board{
    int a[24][24];
    void rotate() {
        int temp[24][24];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                temp[i][j] = a[n-j-1][i];
            }
        }
        memcpy(a, temp, sizeof(temp));
    }
    void move() {
        int temp[24][24];
        for(int i=0; i<n; i++){
            int is = 0, idx =-1;
            for(int j=0; j<n; j++){
                if(!a[i][j])continue;
                else if(is && temp[i][idx] == a[i][j])temp[i][idx] *= 2, is = 0;
                else temp[i][++idx] = a[i][j], is = 1;
            }
            for(++idx; idx<n; idx++){
                temp[i][idx] = 0;
            }
        }
        memcpy(a, temp, sizeof(temp));
    }
    
    void get_max(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ret = max(ret, a[i][j]);
            }
        }
    }
};

void go(Board b, int times){
    if(times == 5) {
        b.get_max();
        return;
    }
    
    for(int i=0; i<4; i++){
        Board c = b;
        c.move();
        go(c, times+1);
        b.rotate();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> ar[i][j];
        }
    }
    Board b;
    memcpy(b.a, ar, sizeof(ar));
    go(b, 0);

    cout << ret << '\n';
    return 0;
}
