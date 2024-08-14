#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

vi f = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
vll pot10 = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int digits(ll a) {
    return (int)floor(1 + log10((long double)a));
}

void solve() {
    string s;
    cin >> s;
    if(s.size() <= 7) {
        int n = stoi(s);
        for(int i=1; i<=10; i++) {
            if(f[i-1] == n) {
                cout << i << '\n';
                return;
            }
        }
    }

    ll factorial = 1;
    int n = 1;
    int len = s.size();
    int cur = 1;

    while(cur < len) {
        n++;
        int d = digits(factorial);
        factorial *= n;
        int d2 = digits(factorial);
        ll mod = pot10[max(0, d2-12)];
        factorial /= mod;
        cur += d2 - d;
    }

    cout << n << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}