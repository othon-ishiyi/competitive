#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class UnionFind {
private:
    vi p, rank, setSize; // vi p is the key part
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0); // optional speedup
        setSize.assign(N, 1); // optional feature
        numSets = N; // optional feature
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    int numDisjointSets() { return numSets; } // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return; // i and j are in same set
            int x = findSet(i), y = findSet(j); // find both rep items
        if (rank[x] > rank[y]) swap(x, y); // keep x ’shorter’ than y
            p[x] = y; // set x under y
        if (rank[x] == rank[y]) ++rank[y]; // optional speedup
            setSize[y] += setSize[x]; // combine set sizes at y
        --numSets; // a union reduces numSets
    }
};


void solve() {
    int N;
    cin >> N;
    UnionFind uf(500001);

    int n, a, count = 0;
    map<int, int> ingredients;
    for(int u=0; u<N; u++) {
        cin >> n;
        while(n--) {
            cin >> a;
            ingredients[uf.findSet(a)]++;
        }

        bool isValid = true;
        for(auto p: ingredients) {
            if(p.second != uf.sizeOfSet(p.first)) {
                isValid = false;
            }
        }

        if(isValid) {
            int potion = ingredients.begin()->first;
            count++;
            while(!ingredients.empty()) {
                uf.unionSet(ingredients.rbegin()->first, potion);
                ingredients.erase(ingredients.rbegin()->first);
            }
        }
        else {
            ingredients.clear();
        }
    }

    cout << count << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}