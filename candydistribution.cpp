#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

ll extEuclid(ll a, ll b, ll &x, ll &y) {
    bool sw = false;
    if(a < b) {
        swap(a,b);
        sw = true;
    }

    ll xx = y = 0;
    ll yy = x = 1;

    while(b) {
        ll q = a/b;
        ll t = b; b = a%b; a = t;
        t = xx; xx = x - q*xx; x = t;
        t = yy; yy = y - q*yy; y = t;
    }

    if(sw) {
        swap(x, y);
    }

    return a;
}

void solve() {
    ll k, c;
    cin >> k >> c;
    ll x, y;

    if (extEuclid(k, c, x, y) != 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    x *= -1;
    y *= -1;

    while(x <= 0) {
        x += c;
        y -= k;
        if(y < -1000000000) {
            cout << "IMPOSSIBLE\n";
            return; 
        }
    }

    while(x >= 0 and y < -1000000000) {
        x -= c;
        y += k;
        if(x <= 0) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    if(y < -1000000000) {
        cout << "IMPOSSIBLE\n";
        return; 
    }
    else {
        cout << -y << '\n';
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    while(cases--)
        solve();
    return 0;
}