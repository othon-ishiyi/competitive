#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int N;
    cin >> N;
    vi routines(N, 0);

    for(int i=0; i<N; i++) {
        string s;
        cin >> s;

        for(char c: s) {
            int shift = c-'A';
            routines[i] += (1 << shift);
        }
    }

    sort(routines.begin(), routines.end());

    int ans = INT_MAX;
    do {
        int cnt = 0;
        for(int i=1; i<N; i++) {
            cnt += __builtin_popcount(routines[i] & routines[i-1]);
        }
        if(cnt >= ans) continue;
        ans = min(ans, cnt);
    } while(next_permutation(routines.begin(), routines.end()));

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}