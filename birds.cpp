#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int l, d, n;
    cin >> l >> d >> n;

    vi pos(n);

    for(int i=0; i<n; i++) {
        cin >> pos[i];
    }

    sort(pos.begin(), pos.end());

    int ans = 0;

    int cur = 6;
    for(auto p: pos) {
        if(p - cur >= d) {
            ans += (p-cur)/d;
        }
        cur = p + d;
    }

    if((l-5) - cur> 0) {
        ans += ((l-6)-cur)/d + 1;
    }

    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}