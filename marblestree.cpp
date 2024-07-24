#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vi g[10010];
int ans=0;

int dfs(int v, vi &marbles) {
    for(auto i: g[v]) {
        marbles[v] += dfs(i, marbles);
    }
    ans += abs(marbles[v] - 1);
    return marbles[v] - 1;
}

void solve(int n) {
    for(int i=0; i<10010; i++) {
        g[i].clear();
    }
    ans = 0;

    vi marbles(n+1);
    int root;

    for(int k=1; k<=n; k++) {
        int i;
        cin >> i;
        if(k == 1) root = i;
        int m;
        cin >> m;
        marbles[i] = m;
        cin >> m;
        for(int j=0; j<m; j++) {
            int a;
            cin >> a;
            g[i].push_back(a);
        }
    }

    dfs(root, marbles);

    cout << ans << '\n';  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(true) {
        cin >> n;
        if(n == 0) break;
        solve(n);
    }
    return 0;
}