#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

class MaxSegTree {
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
        return max(a, b);
    }
    int lazy_to_st(int current_st, int lazy_value, int L, int R) {
        //! If necessary alter this function
        return lazy_value;
    }
    int update_lazy(int current_lazy, int val) {
        //! If necessary alter this function
        return val;
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
    MaxSegTree(int sz) : n(sz), st(4*n) {
        //! If necessary alter neutral value
        neutral_value = -1;
        lazy.assign(4*n, neutral_value);
    }
    MaxSegTree(const vi &initialA) : MaxSegTree((int)initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
    }
    void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }
    int rsq(int i, int j) { return RSQ(1, 0, n-1, i, j); }
};

bool cmp_upper(const int a, const ii b) {
    return a < b.first;
}

bool cmp_lower(const ii a, const int b) {
    return a.first < b;
}

void solve() {
    int N, M;
    int year, rain;
    while(true) {
        map<int, int> idx;
        vi aux;
        scanf("%d", &N);
        aux.assign(N, 0);
        for(int i=0; i<N; i++) {
            scanf("%d %d", &year, &rain);
            idx[year] = i;
            aux[i] = rain;
        }
        scanf("%d", &M);
        if (N == 0 and M == 0) {
            return;
        }
        MaxSegTree st(aux);

        while(M--) {
            int X, Y;
            scanf("%d %d", &Y, &X);
            int u = upper_bound(idx.begin(), idx.end(), Y, cmp_upper)->second;
            int v = idx[X]-1;

            if(idx.count(X) == 0) {
                if(idx[Y], st.rsq(u, v)) {
                    printf("maybe\n");
                    continue;
                }
            }

            else if(aux[idx[X]] > st.rsq(u, v)) {
                if(idx.count(Y) == 0) {
                    printf("maybe\n");
                    continue;
                }
                if(aux[idx[Y]] >= aux[idx[X]]) {
                    if(v-u+2 == X-Y) {
                        printf("true\n");
                        continue;
                    }   
                    printf("maybe\n");
                    continue;
                }
            }
            printf("false\n");
        }
        printf("\n");
    }
}

int main() {

    solve();
    return 0;
}