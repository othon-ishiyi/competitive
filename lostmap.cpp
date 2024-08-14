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
int n;

void kruskal() {
    sort(el.begin(), el.end());
    UnionFind uf(n+1);
    for(auto &[w, i, j]: el) {
        if(!uf.isSameSet(i, j)) {
            cout << i << ' ' << j << '\n';
            uf.merge(i, j);
        }
    }
}

void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int w;
            cin >> w;
            if(i != j) {
                el.push_back({w, i, j});
            }
        }
    }

    kruskal();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}


