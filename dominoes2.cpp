#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vi g[200010];
int visited[200010];
int cnt = 0;

void dfs(int v) {
    visited[v] = 1;
    for(int i: g[v]) {
        if(!visited[i]) {
            dfs(i); 
        }
    }
    cnt++;
}   

void solve() {
    int n, m, l;
    cin >> n >> m >> l;

    for(auto &v: g) {
        v.clear();
    }
    memset(visited, 0, sizeof visited);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    int ans=0;
    for(int i=0; i<l; i++) {
        int a;
        cin >> a;
        cnt = 0;
        if(!visited[a]) {
            dfs(a);
            ans += cnt;
        }
    }

    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    while(N--)
        solve();
    return 0;
}