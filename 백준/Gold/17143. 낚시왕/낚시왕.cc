#include <bits/stdc++.h>
using namespace std;

int R, C, M, r, c, s, d, z, dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, 1, -1}, ar[104][104], ret, temp_ar[104][104];
struct Shark {
    int r, c, s, d, z, die;
};
vector<Shark> v;

void fishing(int idx) {
    int is_catch = 0;
    for(int i=0; i<R; i++){
        if(is_catch)break;
        if(ar[i][idx]){
            ret += ar[i][idx];
            for(int j=0; j<v.size(); j++){
                if(v[j].z == ar[i][idx]){
                    v[j].die = 1;
                    ar[i][idx] = 0;
                    is_catch = 1;
                    break;
                }
            }
        }
    }
}

void kill_shark(int shark_size) {
    for(int i=0; i<v.size(); i++){
        if(v[i].z == shark_size){
            v[i].die = 1;
            break;
        }
    }
}

// void swim() {
//     for(int i=0; i<R; i++){
//         for(int j=0; j<C; j++){
//             if(ar[i][j]){
                
//             }
//         }
//     }
// }

void swim() {
    memset(temp_ar, 0, sizeof(temp_ar));
    for(int i=0; i<v.size(); i++){
        if(v[i].die)continue;
        Shark temp = v[i];
        int idx = temp.s;
        if(temp.d == 0 || temp.d == 1 && idx >= (R-1) * 2)idx %= (R-1) * 2;
        else if(temp.d == 2 || temp.d == 3 && idx >= (C-1) * 2)idx %= (C-1) * 2;
        for(int i=0; i<idx; i++){
            int ny = temp.r + dy[temp.d];
            int nx = temp.c + dx[temp.d];
            if(ny < 0 || nx < 0 || ny >= R || nx >= C){
                temp.d ^= 1;
                ny = temp.r + dy[temp.d];
                nx = temp.c + dx[temp.d];
            }
            temp.r = ny; temp.c = nx;
        }
        if(temp_ar[temp.r][temp.c] > temp.z)temp.die = 1;
        else if(temp_ar[temp.r][temp.c] && temp_ar[temp.r][temp.c] < temp.z){
            kill_shark(temp_ar[temp.r][temp.c]);
            temp_ar[temp.r][temp.c] = temp.z;
        }
        else temp_ar[temp.r][temp.c] = temp.z;
        v[i] = temp;
    }
    memcpy(ar, temp_ar, sizeof(ar));
}

void print() {
    for(int i=0; i<=R; i++){
        for(int j=0; j<=C; j++){
            cout << ar[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main()
{
    cin >> R >> C >> M;
    for(int i=0; i<M; i++){
        cin >> r >> c >> s >> d >> z; r--; c--; d--;
        Shark temp; temp.r = r; temp.c = c; temp.s = s; temp.d = d; temp.z = z;
        v.push_back({temp});
        ar[r][c] = z;
    }
    for(int i=0; i<C; i++){
        // cout << "before" << "\n"; print();
        fishing(i);
        swim();
        // cout << "after" << "\n"; print(); 
    }
    cout << ret << '\n';
    return 0;
}
