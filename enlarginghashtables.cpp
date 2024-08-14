#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

ll sieve_size;
vll p;
bitset<10000010> bs;
ll n;

void sieve(ll upper_bound) {
    sieve_size = upper_bound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i=0; i<sieve_size; i++) {
        if(bs[i]) {
            for(ll j=i*i; j<sieve_size; j+=i) {
                bs[j] = 0;
            }
            p.push_back(i);
        }
    }
}

bool isPrime(ll n) {
    if(n < sieve_size) return bs[n];

    for(auto prime: p) {
        if(prime*prime > n) return true;
        if(n % prime == 0) break;
    }
    return false;
}

void solve() {
    ll k = 2*n+1;
    while(true) {
        if(isPrime(k)) break;
        k++;
    }

    cout << k;

    if(!isPrime(n)) {
        cout << " (" << n << " is not prime)";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(5000000);

    while(cin >> n) {
        if(n == 0) break;
        solve();
    }
    return 0;
}