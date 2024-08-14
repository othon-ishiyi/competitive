#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vi g[1010];
vi visited(1010, 0);
vi dist(1010, INT_MAX);
int maxid=0, ans;
int n;

void bfs() {
    visited[n] = 1;
    dist[n] = 1;
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        if(maxid < dist[v]) {
            maxid = dist[v];
            ans = v;
        }
        else if(maxid == dist[v]) {
            ans = min(ans, v);
        }
        for(int i: g[v]) {
            if(!visited[i]) {
                visited[i] = 1;
                q.push(i);
                dist[i] = dist[v] + 1;
            }
        }
    }
}

void solve() {
    int h, l;
    cin >> n >> h >> l;
    while(h--) {
        int a;
        cin >> a;
        g[n].push_back(a);
    }
    while(l--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs();
    for(int i=0; i<n;i++) {
        if(!visited[i]) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}