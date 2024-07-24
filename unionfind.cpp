#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

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


void solve() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    int a, b;
    char c;
    while(Q--) {
        cin >> c >> a >> b;
        if(c == '=') {
            uf.merge(a, b);
        }
        else if (c == 's') {
            cout << uf.getSize(a) << ' ' << uf.getSize(b) << '\n';
        }
        else {
            cout << (uf.isSameSet(a, b)? "yes\n": "no\n");
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}