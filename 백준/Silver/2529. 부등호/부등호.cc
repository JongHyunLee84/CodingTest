#include <bits/stdc++.h>
using namespace std;

int n, visited[10];
char oper[9];
vector<string> v;
string s;
bool check(char oper, int first, int second){
    if(oper == '<'){
        return first < second;
    }
    else{
        return first > second;
    }
}

void dfs(int num, int turn){
    if(s.size() == n+1){
        v.push_back(s);
        return;    
    }
    for(int i=0; i<10; i++){
        if(check(oper[turn], num, i) && !visited[i]){
            visited[i] = 1;
            s += (i + '0');
               dfs(i, turn+1);
            visited[i] = 0;
            s.erase(s.size()-1, 1);
        }
    }

}

int main() {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> oper[i];
    }
    for(int i=0; i<10; i++){
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        s += (i + '0');
        dfs(i, 0);
        s = "";
    }
    
    sort(v.begin(), v.end());
    cout << v[v.size()-1] << '\n';
    cout << v[0] << '\n';
    
}
