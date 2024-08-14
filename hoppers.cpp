#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vi g[500010];
int visited[500010];
int color[500010];
int n;

bool bipartite(int i, int c) {
    color[i] = c;
    visited[i] = 1;
    bool ans = true;
    for(int v: g[i]) {
        if(!visited[v]) {
            ans *= bipartite(v, 1-c);
        }
        if(visited[v] and color[v] == c) {
            ans = false;
        }
    }
    return ans;
}

void solve() {
    memset(visited, 0, sizeof visited);
    int m;
    cin >> n >> m;

    while(m--) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool bip = true;
    int cc = 0;

    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            bip *= bipartite(i, 0);
            cc++;
        }
    }
    
    cout << cc - 1 + (bip == true) << '\n';
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}