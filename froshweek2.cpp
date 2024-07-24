#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int n, m;
    cin >> n >> m;

    vi t(n), p(m);

    for(int i=0; i<n; i++) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    for(int i=0; i<m; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    auto it = p.begin();
    int ans = 0;
    for(auto i: t){
        while(*it < i and it != p.end()) {
            it++;
        }
        if(it == p.end()) break;
        ans++;
        it++;
    }

    cout << ans << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}