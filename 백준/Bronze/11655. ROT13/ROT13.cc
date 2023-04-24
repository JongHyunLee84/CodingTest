#include <bits/stdc++.h>
using namespace std;

string w;

int main() {
    getline(cin, w);
    for(int i = 0; i < w.size(); i++){
        if (w[i] >= 65 && w[i] <= 'Z') {
            if(w[i] + 13 > 'Z') {
                w[i] = (w[i] + 13) - 26;
            } else {
                w[i] = w[i] + 13;
            }
        } else if (w[i] >= 97 && w[i] <= 'z') {
            if(w[i] + 13 > 'z') {
                w[i] = (w[i] + 13) - 26;
            } else {
                w[i] = w[i] + 13;
            }
        } 
    }
    cout << w;
    return 0;
}
    
