#include <bits/stdc++.h>
using namespace std;

int order, A, B, ar[1004], br[1004], ret;
map<int, int> mp1, mp2;
int main()
{
    cin >> order >> A >> B;
    for(int i=0; i<A; i++)cin >> ar[i];
    for(int i=0; i<B; i++)cin >> br[i];
    
    for(int i=0; i<A; i++){
        int temp = 0;
        temp += ar[i];
        if(temp == order){ret++; continue;}
        else if(temp < order) mp1[temp]++;
        for(int j=i+1; j<A+i-1; j++){
            temp += ar[j%A];
            if(temp == order){ret++; break;}
            else if(temp < order)mp1[temp]++;
        }
    }
    for(int i=0; i<B; i++){
        int temp = 0;
        temp += br[i];
        if(temp == order){ret++; continue;}
        else if(temp < order)mp2[temp]++;
        for(int j=i+1; j<B+i-1; j++){
        temp += br[j%B];
        if(temp == order){ret++; break;}
        else if(temp < order)mp2[temp]++;
        }
    }
    int temp = 0;
    for(int i=0; i<A; i++){
        temp += ar[i];
    }
    if(temp == order)ret++;
    else if(temp < order)mp1[temp]++;
    temp = 0;
    for(int i=0; i<B; i++){
        temp += br[i];
    }
    if(temp == order)ret++;
    else if(temp < order)mp2[temp]++;
    
    for(int i=1; i<order; i++){
        int a = i;
        int b = order - a;
        ret += mp1[a] * mp2[b];
    }

    cout << ret << '\n';
    return 0;
}
