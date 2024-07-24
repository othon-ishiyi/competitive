#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class ModifiedUnionFind {
private:
    vi p, rank, setSize, setSum; // vi p is the key part
    int numSets;
public:
    ModifiedUnionFind(int N) {
        p.assign(2*N, 0); 
        setSum.assign(2*N, 0);
        for (int i = 0; i < N; ++i){
            p[i] = p[i+N] = i+N;
            setSum[i] = setSum[i+N] = i;
        }
        rank.assign(2*N, 0);
        setSize.assign(2*N, 1);
        numSets = N;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    int numDisjointSets() { return numSets; } // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
    int sumOfSet(int i) {return setSum[findSet(i)];}
    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return; // i and j are in same set
            int x = findSet(i), y = findSet(j); // find both rep items
        if (rank[x] > rank[y]) swap(x, y); // keep x ’shorter’ than y
        p[x] = y; // set x under y
        if (rank[x] == rank[y]) ++rank[y]; // optional speedup
        setSize[y] += setSize[x];
        setSum[y] += setSum[x];
        
        --numSets; 
    }
    void move(int i, int j) {
        if(isSameSet(i, j))
            return;
        setSize[findSet(i)]--;
        setSize[findSet(j)]++;
        setSum[findSet(i)] -= i;
        setSum[findSet(j)] += i;
        p[i] = findSet(j);
    }
};


void solve(int n, int m) {
    int cmd, p, q;
    ModifiedUnionFind muf(n+1);
    while(m--) {
        cin >> cmd;
        if(cmd == 1) {
            cin >> p >> q;
            muf.unionSet(p, q);
        }
        else if(cmd == 2) {
            cin >> p >> q;
            muf.move(p, q);
        }
        else {
            cin >> p;
            cout << muf.sizeOfSet(p) << ' ' << muf.sumOfSet(p) << '\n';
        }
    }

}

int main() {
    int n, m;
    while(cin >> n >> m){
        solve(n, m);
    }
    return 0;
}