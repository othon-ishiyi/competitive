    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<ll> vll;
    typedef vector<vector<int>> vvi;
    typedef pair<int,int> ii;

    ll _sieve_size;
    vll primes;
    unordered_map<ll, int> cnt, f[101];
    ll n;
    bitset<10000010> bs;

    void sieve(ll upperbound) {
        _sieve_size = upperbound+1;
        bs.set();
        bs[0] = bs[1] = 0;
        for(ll i=0; i<_sieve_size; i++) {
            if(bs[i]) {
                for(ll j=i*i; j<_sieve_size; j+=i) {
                    bs[j] = 0;
                }
                primes.push_back(i);
            }
        }
    }

    void factorize(ll n, int idx) {
        for(int i=0; i<primes.size(); i++) {
            ll p = primes[i];
            if(n < p*p) break;
            while(n % p == 0) {
                n /= p;
                cnt[p]++;
                f[idx][p]++;
            }
        }
        if(n != 1) {
            cnt[n]++;
            f[idx][n]++;
        }
    }


    void solve() {
        cin >> n;
        vi v;
        for(int i=0; i<n; i++) {
            ll a;
            cin >> a;
            factorize(a, i);
            v.push_back(a);
        }

        ll ans = 1;
        ll moves = 0;

        for(auto k: cnt) {
            int e = k.second/n;
            ll factor = 1;
            for(int i=0; i<e; i++)
                factor *= k.first;
            if(e) {
                ans *= factor;
                for(int i=0; i<v.size(); i++) {
                    int c = f[i][k.first];
                    moves += max(0, e-c);
                }
            }       
        }

        cout << ans << ' ' << moves << '\n';
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sieve(1001);

        solve();
            
        return 0;
    }