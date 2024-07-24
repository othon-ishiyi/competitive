#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#define LSOne(x) ((x) & -(x))

void solve(int N, int M) {
    vi info[21];
    for(int i=0; i<M; i++) {
        int x, y;
        cin >> x >> y;

        info[x].push_back(y);
    }

    int ans = 0;

    for(int i=(1 << N) - 1; i >= 0; i--) {
        int j=i;
        bool valid = true;
        while(j > 0 and valid) {
            int lsone = LSOne(j);
            int informant = __builtin_ctz(lsone) + 1;
            for(int u=0; u<info[informant].size(); u++) {
                int shift = abs(info[informant][u]) - 1;
                if(info[informant][u] > 0 and ((i & (1 << shift)) == 0)) {
                    valid = false;
                    break;
                }
                if(info[informant][u] < 0 and (i & (1 << shift))) {
                    valid = false;
                    break;
                }
            }
            j -= lsone;
        }
        if(valid) {
            ans = max(__builtin_popcount(i), ans);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;

    while(true) {
        cin >> N >> M;
        if(N==0) return 0;
        solve(N, M);
    }
    return 0;
}