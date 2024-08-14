#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vector<pair<ii,int>> g[1001][1001];
int dist[1001][1001];
ii parent[1001][1001];
int h, w;
ii start, dest;

struct cmp{
    bool operator()(ii a, ii b) const {
        return dist[a.first][a.second] > dist[b.first][b.second];
    }
};

bool isValid(int x, int y) {
    if(x>=0 and x<h and y>=0 and y<w) return true;
    return false;
}

void bfs() {
    dist[start.first][start.second] = 0;
    set<ii, cmp> q;
    q.insert(start);
    while(!q.empty()) {
        auto v = q.begin(); q.erase(v);
        int x = v->first;
        int y = v->second;
        for(auto &[p,c]: g[x][y]) {
            int i = p.first, j = p.second;
            if(dist[i][j] > dist[x][y] + c) {
                dist[i][j] = dist[x][y] + c;
                parent[i][j] = *v;
                if(q.count(p)) {
                    q.erase(p);
                }
                q.insert(p);
            }
        }
    }
}

void solve() {
    cin >> h >> w;
    vector<ii> moves = {{-1,0}, {-1, 1}, {0, 1},
                        {1, 1}, {1, 0}, {1,-1},
                        {0, -1}, {-1,-1}};

    for(int i=0; i<h; i++) {
        string s;
        cin >> s;
        for(int j=0; j<w; j++) {
            int a = s[j]-'0';
            for(int k=0; k<8; k++) {
                int u=moves[k].first+i, v=moves[k].second+j;
                if(isValid(u,v)) {
                    if(k == a) {
                        g[i][j].push_back({{u,v}, 0});
                    }
                    else {
                        g[i][j].push_back({{u,v}, 1});
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        for(int i=0; i<1001; i++) {
            for(int j=0; j<1001; j++) {
                dist[i][j] = INT_MAX;
            }
        }
        cin >> start.first >> start.second >> dest.first >> dest.second;
        start.first--;
        start.second--;
        dest.first--;
        dest.second--;
        bfs();
        cout << dist[dest.first][dest.second] << '\n';
        /* ii cur = dest;
        while(cur != start) {
            cout << '{' << cur.first << ',' << cur.second << "} ";
            cur = parent[cur.first][cur.second];
        }
        cout << '\n';  */
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}