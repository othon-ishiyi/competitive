#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int n, l;
    cin >> l >> n;
    int ans_min = 0, ans_max = 0;

    while(n--) {
        int a;
        cin >> a;
        ans_min = max(ans_min, min(a, l-a));
        ans_max = max(ans_max, max(a, l-a));
    }

    cout << ans_min << ' ' << ans_max << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while(n--)
        solve();
    return 0;
}