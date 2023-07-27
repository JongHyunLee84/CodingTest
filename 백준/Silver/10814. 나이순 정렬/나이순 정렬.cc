#include <bits/stdc++.h>
using namespace std;

int n, a;
string s;
struct Person {
    int age, sign;
    string name;
};
vector<Person> v;

bool comp(Person p1, Person p2){
    if(p1.age == p2.age){
        return p1.sign < p2.sign;
    }
    return p1.age < p2.age;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> s;
        Person p;
        p.age = a; p.sign = i; p.name = s;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), comp);
    for(auto i : v)cout << i.age << ' ' << i.name << '\n';
    return 0;
}
