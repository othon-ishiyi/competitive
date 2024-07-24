#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int n;
    cin >> n;
    vi s(n+1);

    while(n--) {
        int a;
        cin >> a;
        s[a] = n;
    }

    for(int i=2; i<s.size(); i++) {
        if(s[i] > s[i-1]) {
            cout << s.size()-i << '\n';
            return;
        }
    }
    cout << 0 << '\n';
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