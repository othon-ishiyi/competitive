#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vi g[200010];
int visited[200010];

void dfs(int v) {
    visited[v] = 1;
    for(int i: g[v]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}   

void solve() {
    int n, m;
    cin >> n >> m;

    memset(visited, 0, sizeof visited);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);

    int cnt = 0; 
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            cout << i << '\n';
            cnt++;
        }
    }

    if(cnt == 0) {
        cout << "Connected\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}