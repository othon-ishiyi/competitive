#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;


void solve() {
    int n, a;
    cin >> n;
    set<ii> s;

    vi degree(n+1, 1);
    vi prufer(n, 0);
    vi ans(n, 0);
    for(int i=0; i<n; i++){
        cin >> a;
        degree[a]++;
        prufer[i] = a;
    }
    for(int i=1; i<=n; i++){
        s.insert({degree[i], i});
    }
    for(int i=0; i<n; i++) {
        if(s.begin()->first != 1) {
            cout << "Error\n";
            return;
        }
        ans[i] = s.begin()->second;
        s.erase(s.begin());
        s.erase({degree[prufer[i]]--, prufer[i]});
        s.insert({degree[prufer[i]], prufer[i]});
    }

    for(int i: ans) {
        cout << i << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}