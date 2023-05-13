#include <bits/stdc++.h>
using namespace std;

int n;
double temp;
priority_queue<double> pq;
int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        if(pq.size() < 7)pq.push(temp);
        else {
            if(pq.top() > temp){
                pq.pop();
                pq.push(temp);
            }
        }
    }
    vector<double> v;
    while(pq.size()){
        v.push_back(pq.top());
        pq.pop();
    }
    reverse(v.begin(), v.end());
    for(double i : v) printf("%.3lf\n", i); 
    return 0;
}
