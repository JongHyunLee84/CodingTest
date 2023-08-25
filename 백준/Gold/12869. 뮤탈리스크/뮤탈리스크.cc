#include <bits/stdc++.h>
using namespace std;

int n, visited[64][64][64];
vector<int> v(3);
int attack[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 9, 3},
    {1, 3, 9}
};
struct SCV {
    int a, b, c;
};
queue<SCV> q;

void solve(int a, int b, int c){
    SCV temp; temp.a = a; temp.b = b; temp.c = c;
    q.push(temp);
    visited[a][b][c] = 1;
    
    while(q.size()){
        SCV now = q.front(); q.pop();
        if(visited[0][0][0])break;
        for(int i=0; i<6; i++){
            int na = max(0, now.a - attack[i][0]);
            int nb = max(0, now.b - attack[i][1]);
            int nc = max(0, now.c - attack[i][2]);
            if(visited[na][nb][nc])continue;
            visited[na][nb][nc] = visited[now.a][now.b][now.c] + 1;
            q.push({na,nb,nc});
        }
    }
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    solve(v[0], v[1], v[2]);
    cout << visited[0][0][0] - 1 << '\n';

    return 0;
}
