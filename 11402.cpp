#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

class SegmentTree {
private:
    int n; // n = (int)A.size()
    vi A, st, lazy; // the arrays
    int neutral_value;
    int l(int p) {
        return p<<1;
    } // go to left child
    int r(int p) {
        return (p<<1)+1;
    } // go to right child
    int conquer(int a, int b) {
        if (a == -1) return b;
        if (b == -1) return a;
        //! If necessary alter the conquer function
        return a + b;
    }
    int lazy_to_st(int cur_value, int lazy_value, int L, int R) {
        //! If necessary alter this function
        if(lazy_value == 0)
            return cur_value;
        else if(lazy_value == 1)
            return R-L+1;
        else if(lazy_value == 2)
            return 0;
        else
            return R-L+1 - cur_value;
    }
    int update_lazy(int cur_lazy, int val) {
        //! If necessary alter this function
        if(val == 1 or val == 2) {
            return val;
        }
        // If val = 3
        if(cur_lazy == 0) {
            return val;
        }
        else if (cur_lazy == 1 or cur_lazy == 2){
            return 3 - cur_lazy;
        }
        else {
            return 0;
        }
    }
    void build(int p, int L, int R) {
        if (L == R)
            st[p] = A[L];
        else {
            int m = (L+R)/2;
            build(l(p), L , m);
            build(r(p), m+1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }
    void propagate(int p, int L, int R) {
        if (lazy[p] != neutral_value) {
            st[p] = lazy_to_st(st[p], lazy[p], L, R);
            if (L != R) {
                lazy[l(p)] = update_lazy(lazy[l(p)], lazy[p]);
                lazy[r(p)] = update_lazy(lazy[r(p)], lazy[p]);
            }
            else
                A[L] = lazy[p];
            lazy[p] = neutral_value; // erase lazy flag
        }
    }
    int RSQ(int p, int L, int R, int i, int j) {    
        propagate(p, L, R); // lazy propagation
        if (i > j) return neutral_value; // infeasible
        if ((L >= i) && (R <= j))
            return (lazy[p] != neutral_value) ? lazy_to_st(st[p], lazy[p], L, R): st[p]; // found the segment
        int m = (L+R)/2;
        int ans = conquer(RSQ(l(p), L , m, i , min(m, j)),
            RSQ(r(p), m+1, R, max(i, m+1), j ));
        return ans;
    }

    void update(int p, int L, int R, int i, int j, int val) { // O(log n)
        propagate(p, L, R); // lazy propagation
        if (i > j) return;
        if ((L >= i) && (R <= j)) { // found the segment
            lazy[p] = update_lazy(lazy[p], val);
            propagate(p, L, R); // lazy propagation
        }
        else {
            int m = (L+R)/2;
            update(l(p), L , m, i , min(m, j), val);
            update(r(p), m+1, R, max(i, m+1), j , val);
            int lsubtree = (lazy[l(p)] != neutral_value) ? lazy_to_st(st[l(p)], lazy[l(p)], L, m): st[l(p)];
            int rsubtree = (lazy[r(p)] != neutral_value) ? lazy_to_st(st[r(p)], lazy[r(p)], m+1, R): st[r(p)];
            st[p] = conquer(lsubtree, rsubtree);
        }
    }
public:
    SegmentTree(int sz) : n(sz), st(4*n) {
        //! If necessary alter neutral value
        neutral_value = 0;
        lazy.assign(4*n, neutral_value);
    }
    SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
    }
    void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }
    int rsq(int i, int j) { return RSQ(1, 0, n-1, i, j); }
};

void solve() {
    vi initialA;
    string s;
    int M, T;
    cin >> M;
    while(M--) {
        cin >> T >> s;
        vi vaux;
        for(char c: s) {
            vaux.push_back(c - '0');
        }
        while(T--) {
            initialA.insert(initialA.end(), vaux.begin(), vaux.end());
        }
    }
    
    SegmentTree st(initialA);

    int Q;
    cin >> Q;
    char c;
    int a, b;
    int count_s = 0;
    while(Q--) {
        cin >> c >> a >> b;
        if(c == 'F') {
            st.update(a, b, 1);
        }
        else if(c == 'E') {
            st.update(a, b, 2);
        }
        else if(c == 'S') {
            cout << 'Q' << ++count_s << ": " << st.rsq(a, b ) << '\n';
        }
        else {
            st.update(a, b, 3);
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i=1; i<=T; i++){
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}