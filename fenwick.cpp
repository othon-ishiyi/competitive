#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#define LSOne(S) ((S) & -(S))

class FenwickTree {
private:
    vll ft;
public:
    FenwickTree(int m) { ft.assign(m+1, 0); } // create an empty FT
    void build(const vll &f) {
        int m = (int)f.size()-1;
        ft.assign(m+1, 0);
        for (int i = 1; i <= m; ++i) {
            ft[i] += f[i];
            if (i+LSOne(i) <= m)
                ft[i+LSOne(i)] += ft[i];
        }
    }
    FenwickTree(const vll &f) { build(f); }
    FenwickTree(int m, const vi &s) { 
        vll f(m+1, 0);
        for (int i = 0; i < (int)s.size(); ++i)
            ++f[s[i]];
        build(f);
    }
    ll rsq(int j) { // returns RSQ(1, j)
        ll sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }

    ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } // inc/exclusion

    void update(int i, ll v) {
        for (; i < (int)ft.size(); i += LSOne(i))
        ft[i] += v;
    }
    int select(ll k) { // O(log^2 m)
        int lo = 1, hi = ft.size()-1;
        for (int i = 0; i < 30; ++i) { // 2^30 > 10^9; usually ok
            int mid = (lo+hi) / 2; // BSTA
            (rsq(1, mid) < k) ? lo = mid : hi = mid; // See Section 3.3.1
        }
        return hi;
    }
};

void solve() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    FenwickTree ft(N);
    char c;
    int a;
    ll b;
    while(Q--) {
        scanf(" %c", &c);
        if(c == '+') {
            scanf("%d %Ld", &a, &b);
            ft.update(a+1, b);
        }
        else {
            scanf("%d", &a);
            printf("%Ld\n", ft.rsq(a));
        }
    }
}

int main() {

    solve();
    return 0;
}