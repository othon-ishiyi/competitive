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
        int n;
        cin >> n;
        vll v(n+1);
        vll ft_start(n+1, 1);
        for(int i=1; i<=n; i++) {
            cin >> v[i];
        }

        FenwickTree ft(ft_start);
        int p = 1;
        while(n > 1) {
            int aux = (p - 1 + v[ft.select(p)]) % n;
            if(aux == 0) aux = n;
            int val = ft.select(aux);
            ft.update(val, -1);
            n--;
            p = (ft.rsq(ll(val)) + 1) % n;
            if(p == 0) p = n;
        }

        cout << ft.select(1) << '\n';
    }

    int main() {

        solve();
        return 0;
    }