#include <bits/stdc++.h>
using namespace std;

int n;
double ar[10004], ret, temp;

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)cin >> ar[i];
    for(int i=0; i<n; i++){
        temp = ar[i];
        for(int j=i+1; j<n; j++){
            if(ar[j]==0)break;
            temp *= ar[j];
            ret = max(ret, temp);
        }
        ret = max(ret, temp);
        
    }
    printf("%.3lf\n", ret);
    return 0;
}
