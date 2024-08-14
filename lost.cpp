#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vector<ii> g[1010];
vector<ii> visited(1010, {-1,-1});
vi dist(1010, INT_MAX);
int n;
int ans = 0;

void bfs() {
    visited[n] = {0, 0};
    dist[n] = 1;
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(auto &[i, c]: g[v]) {
            if(visited[i].first == -1) {
                dist[i] = dist[v] + 1;
                visited[i] = {dist[i], c};
                q.push(i);
                ans += c;
            }
            else if(visited[i].first == dist[v]+1) {
                if(c < visited[i].second) {
                    ans += c - visited[i].second;
                    visited[i].second = c;
                }
            }
        }
    }
}

void solve() {
    int m;
    cin >> n >> m;
    unordered_map<string, int> um;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        um[s] = i;
    }
    um["English"] = n;
    while(m--) {
        string sa, sb;
        int a, b, c;
        cin >> sa >> sb >> c;
        a = um[sa]; b = um[sb];
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    bfs();

    for(int i=0; i<n; i++) {
        if(visited[i].first == -1) {
            cout << "Impossible\n";
            return;
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