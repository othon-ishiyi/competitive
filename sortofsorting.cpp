#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int,int>>

using namespace std;

void solve(int N) {
    vector<tuple<char, char, int>> v;
    vector<string> names;
    string s;

    for(int i=0; i<N; i++){
        cin >> s;
        names.push_back(s);
        v.push_back({s[0], s[1], i});
    }

    sort(v.begin(), v.end());

    for(auto t: v){
        cout << names[get<2>(t)] << "\n";
    }
}

int main() {
    while(true){
        int N;
        cin >> N;
        if(N==0)
            return 0;
        solve(N);
        cout << "\n";
    }
    return 0;
}