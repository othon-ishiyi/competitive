#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

ll _sieve_size;
vll primes;
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

void factorize(ll n) {
    int cnt = 0;
    for(ll p: primes) {
        if(p*p > n) break;
        while(n % p == 0) {
            n /= p;
            cnt++;
        }
        if(cnt > 1) {
            cout << p << '^' << cnt << ' ';
        }
        else if(cnt) {
            cout << p << ' ';
        }
        cnt = 0;
    }
    if(n > 1) {
        cout << n;
    }
}

void solve() {
    if(n < 0) {
        cout << -1 << ' ';
        n *= -1;
    }
    factorize(n);
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(100000);
    while(cin >> n)
        solve();
    return 0;
}