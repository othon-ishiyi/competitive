/*https://atcoder.jp/contests/abc357/tasks/abc357_f*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;

ll mod = 998244353;

class Node {
public:
    ll a, b, prod;
    Node(ll a, ll b, ll prod) {
        this->a = a;
        this->b = b;
        this->prod = prod;
    }

    Node() {
        a = ll(0);
        b = ll(0);
        prod = ll(0);
    }

    Node operator+(Node const& other) {
        return Node((a+other.a)%mod, (b+other.b)%mod, (prod+other.prod)%mod) ;
    }

    bool operator!=(Node const& other) {
        return (a%mod != other.a%mod) or (b%mod != other.b%mod) or (prod%mod != other.prod%mod);
    }
};

class SegmentTree {
private:
    int n;
    vector<Node> A, st, lazy; // the arrays
    Node neutral_value;
    int l(int p) {
        return p<<1;
    } // go to left child
    int r(int p) {
        return (p<<1)+1;
    } // go to right child
    Node conquer(Node e1, Node e2) {
        return e1+e2;
    }
    Node lazy_to_st(Node current_st, Node lazy_value, int L, int R) {
        //! If necessary alter this function
        return Node((current_st.a+ll(R-L+1)*lazy_value.a)%mod,
                       (current_st.b+ll(R-L+1)*lazy_value.b)%mod,
                       (current_st.prod+(current_st.a*lazy_value.b)%mod + (current_st.b*lazy_value.a)%mod + ll(R-L+1)*((lazy_value.a*lazy_value.b)%mod))%mod);
    }
    Node update_lazy(Node current_lazy, Node val) {
        //! If necessary alter this function
        return current_lazy + val;
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
    Node RSQ(int p, int L, int R, int i, int j) {    
        propagate(p, L, R); // lazy propagation
        if (i > j) return neutral_value; // infeasible
        if ((L >= i) && (R <= j))
            return (lazy[p] != neutral_value) ? lazy_to_st(st[p], lazy[p], L, R): st[p]; // found the segment
        int m = (L+R)/2;
        Node ans = conquer(RSQ(l(p), L , m, i , min(m, j)),
            RSQ(r(p), m+1, R, max(i, m+1), j ));
        return ans;
    }

    void update(int p, int L, int R, int i, int j, Node val) { // O(log n)
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
            Node lsubtree = (lazy[l(p)] != neutral_value) ? lazy_to_st(st[l(p)], lazy[l(p)], L, m): st[l(p)];
            Node rsubtree = (lazy[r(p)] != neutral_value) ? lazy_to_st(st[r(p)], lazy[r(p)], m+1, R): st[r(p)];
            st[p] = conquer(lsubtree, rsubtree);
        }
    }
public:
    SegmentTree(const vector<Node> &initialA) {
        n = initialA.size();
        //! Define neutral_value
        neutral_value = Node();
        lazy.assign(4*n, neutral_value);
        st.assign(4*n, neutral_value);
        A = initialA;
        build(1, 0, n-1);
    }
    void update(int i, int j, Node val) { update(1, 0, n-1, i, j, val); }
    Node rsq(int i, int j) { return RSQ(1, 0, n-1, i, j); }
};


int main() {
    int N, Q;
    cin >> N >> Q;
    vl a(N), b(N);
    vector<Node> A;
    for(int i=0; i<N; i++) {
        cin >> a[i];
    }
    for(int i=0; i<N; i++) {
        cin >> b[i];
    }
    for(int i=0; i<N; i++) {
        A.push_back(Node(a[i], b[i], a[i]*b[i]));
    }

    SegmentTree st(A);

    while(Q--) {
        int u, l, r;
        ll x;
        cin >> u >> l >> r;
        l--; r--;
        if(u == 1) {
            cin >> x;
            st.update(l, r, Node(x, 0, 0));
        }
        else if(u == 2) {
            cin >> x;
            st.update(l, r, Node(0, x, 0));
        }
        else {
            cout << st.rsq(l, r).prod%mod << '\n';
        }
    }
    return 0;
}