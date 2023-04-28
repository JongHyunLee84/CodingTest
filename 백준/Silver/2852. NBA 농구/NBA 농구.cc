#include <bits/stdc++.h>
using namespace std;
int n, which, game = 48;
string times;
map<int, int> mp, mp2;
pair<int, string> p;

vector<string> split(string input, string delimiter)
{
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while ((pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    if (input != "")
        ret.push_back(input);
    return ret;
}
int to_seconds(string time)
{
    vector<string> v = split(time, ":");
    int ret = 0;
    ret += stoi(v[0]) * 60;
    ret += stoi(v[1]);
    return ret;
}
string to_minute(int seconds){
    int m, s; string ret;
    m = seconds / 60;
    s = seconds % 60;
    if(m<10){
        ret += "0"+ to_string(m);
    } else {
        ret += to_string(m);
    }
    ret += ":";
    if(s<10){
        ret += "0"+ to_string(s);
    } else {
        ret += to_string(s);
    }
    return ret;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> which >> times;
        mp[which]++;
        if (mp[1] == mp[2]){
            if (p.first == 1)
            {
                mp2[1] += to_seconds(times) - to_seconds(p.second);
            } else if (p.first == 2) {
                mp2[2] += to_seconds(times) - to_seconds(p.second);
            }
            p = {0, times};
        }
            
        else if (mp[1] > mp[2])
        {
            if (p.first == 1)
            {
                mp2[1] += to_seconds(times) - to_seconds(p.second);
            } else if (p.first == 2) {
                mp2[2] += to_seconds(times) - to_seconds(p.second);
            }
            p.first = 1;
            p.second = times;
        }
        else
        {
            if (p.first == 2)
            {
                mp2[2] += to_seconds(times) - to_seconds(p.second);
            } else if(p.first == 1) {
                mp2[1] += to_seconds(times) - to_seconds(p.second);
            }
            p.first = 2;
            p.second = times;
        }
        if (i == n - 1)
        {
            if (mp[1] == mp[2])
                continue;
            else if (mp[1] > mp[2])
            {
                mp2[1] += to_seconds("48:00") - to_seconds(p.second);
            }
            else
            {
                mp2[2] += to_seconds("48:00") - to_seconds(p.second);
            }
        }
    }
    for (int i = 1; i <= 2; i++)
    {
        cout << to_minute(mp2[i]) << '\n';
    }
    return 0;
}

