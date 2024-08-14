#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;

class UnionFind {
private:
    vi p, rank, size;
public:
    UnionFind(int n) {
        p.assign(n, 0);
        for(int i=0; i<n; i++) {
            p[i] = i;
        }
        rank.assign(n, 0);
        size.assign(n, 1);
    }

    int findSet(int i) {
        if(p[i] != i){
            p[i] = findSet(p[i]);
        }
        return p[i];
    }

    int getSize(int i) {
        return size[findSet(i)];
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void merge(int i, int j) {
        if(isSameSet(i, j))
            return;
        if(rank[i] < rank[j]) {
            swap(i, j);
        }
        size[findSet(i)] = getSize(i) + getSize(j);
        p[findSet(j)] = findSet(i);
        if(rank[findSet(i)] == rank[findSet(j)]) {
            rank[findSet(i)]++;
        }
    }
};

vector<iii> el;
vector<ii> g[1000010];
int grid[1001][1001];
bool visited[1000010];
int ans;

int r, c;

bool isValid(int x, int y) {
    if(x > 0 and x <= r and y > 0 and y <= c) {
        return true;
    }
    return false;
}

void kruskal() {
    sort(el.begin(), el.end());
    UnionFind uf(r*c+2);
    for(auto &[w, i, j]: el) {
        if(!uf.isSameSet(i, j)) {
            g[i].push_back({j, w});
            g[j].push_back({i, w});
            uf.merge(i, j);
        }
    }
}

void dfs(int i, int d) {
    visited[i] = 1;
    if(i == r*c+1) {
        ans = d;
    }
    for(auto &[v, w]: g[i]) {
        if(!visited[v]) {
            dfs(v, max(d, w));
        }
    }
}

void solve() {
    vector<ii> moves = {{1, 0},{0, 1}};
    cin >> r >> c;
    memset(visited, 0, sizeof visited);

    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            for(auto &[dx, dy]: moves) {
                int u=i+dx, v=j+dy;
                if(isValid(u, v)) {
                    int w = max(grid[i][j], grid[u][v]);
                    el.push_back({w,(i-1)*c+j, (u-1)*c+v});
                }
            }
        }
    }

    for(int i=1; i<=r; i++) {
        el.push_back({0, (i-1)*c+1, 0});
        el.push_back({0, (i-1)*c+c, r*c+1});
    }

    kruskal();
    dfs(0, 0);

    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}