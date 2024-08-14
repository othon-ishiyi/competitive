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
int n, r, states;
ld road, rail;

int dist(ii a, ii b) {
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

void kruskal() {
    road = rail = 0;
    states = 1;
    sort(el.begin(), el.end());
    UnionFind uf(n+1);
    for(auto &[w, i, j]: el) {
        if(!uf.isSameSet(i, j)) {
            if(w > r) {
                rail += sqrt(ll(w));
                states++;
            }
            else road += sqrt(ll(w));
            uf.merge(i, j);
        }
    }
}

void solve() {
    cin >> n >> r;
    r = r*r;

    el.clear();

    vector<ii> v;

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i != j) {
                int w = dist(v[i], v[j]);
                el.push_back({w, i, j});
            }
        }
    }

    kruskal();

    cout << states << ' ' << round(road) << ' ' << round(rail) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;

    for(int i=1; i<=cases; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}


