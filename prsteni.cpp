#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

ll gcd(ll a, ll b) {
    if(a < b) swap(a,b);
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    int a;
    cin >> a;
    while(--n) {
        int b;
        cin >> b;
        int g = gcd(a,b);
        cout << a/g << '/' << b/g << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}