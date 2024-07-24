#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve(string str) {
    stringstream ss;
    ss << str;
    vi v;
    int a;

    while(ss >> a) {
        v.push_back(a);
    }

    set<int> s;
    int n = 0;
    for(int i=0; i<v.size(); i++) {
        if(v[i] > n)
            n = v[i];
        for(int j=i+1; j<v.size(); j++) {
            if(s.count(abs(v[j]-v[i]))) {
                cout << "not a ruler\n";
                return;
            }
            s.insert(abs(v[j]-v[i]));
        }
    }

    if(s.size() == n) {
        cout << "perfect\n";
        return;
    }

    cout << "missing";
    int missing = 1;

    for(int i: s) {
        while(missing < i) {
            cout << ' ' << missing++;
        }
        missing = i+1;
    }

    cout << '\n';

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    while(getline(cin, s)) {
        solve(s);
    }

    return 0;
}