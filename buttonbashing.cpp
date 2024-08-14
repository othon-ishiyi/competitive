#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#define NMAX 3600

vi g[NMAX+1];
vi visited(NMAX+1, 0);
vi moves(20,0);
vi possible;
vi dist(NMAX+1, INT_MAX);
int n;

void fill(int i) {
    visited[i] = 1;
    possible.push_back(i);
    for(int u=0; u<n; u++) {
        int next = i+moves[u];
        if(next < 0) next = 0;
        if(next > NMAX) next = NMAX;
        g[i].push_back(next);
        if(!visited[next]) {
            fill(next);
        }
    }
}

void bfs() {
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    visited[0] = 1;

    while(!q.empty()) {
        int v = q.front();
        q.pop();
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
    int t;
    possible.clear();
    for(auto &v: g) {
        v.clear();
    }
    visited.assign(NMAX+1, 0);
    dist.assign(NMAX+1, INT_MAX);
    cin >> n >> t;
    for(int i=0; i<n; i++) {
        cin >> moves[i];
    }
    fill(0);
    sort(possible.begin(), possible.end());
    visited.assign(NMAX+1, 0);

    bfs();
    int pressed = *lower_bound(possible.begin(), possible.end(), t);
    cout << dist[pressed] << ' ' << pressed - t << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;

    while(cases--)
        solve();
    return 0;
}