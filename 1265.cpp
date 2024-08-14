#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
int n, cur = 0;
int A[5001][5001];
int B[5001][5001];

int kruskal() {
    sort(el.begin(), el.end());
    UnionFind uf(n+1);
    int ans = 0;
    for(auto &[w, i, j]: el) {
        if(!uf.isSameSet(i, j)) {
            int x = uf.findSet(i), y = uf.findSet(j);
            uf.merge(i, j);
            int internal = INT_MAX, external = 0;
            int s = uf.findSet(i);
            for(int v=1; v<=n; v++) {
                A[s][v] = A[v][s] = min(A[x][v], A[y][v]);
                B[s][v] = B[v][s] = max(B[x][v], B[y][v]);
                if(uf.isSameSet(i, v)) {
                    internal = min(internal, A[s][v]);
                }
                else {
                    external = max(external, B[s][v]);
                }
            }
            if(internal > external) {
                ans += uf.getSize(i);
            }
        }
    }

    return ans;  
}

void solve() {
    int m;
    cin >> n >> m;

    el.clear();

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            A[i][j] = INT_MAX;
            B[i][j] = 0;
        }
    }

    while(m--) {
        int a, b, w;
        cin >> a >> b >> w;
        el.push_back({-w, a, b});
        cur = min(cur, -w);
        A[a][b] = w;
        A[b][a] = w;
        B[a][b] = w;
        B[b][a] = w;
    }

    cout << kruskal() << '\n';
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


