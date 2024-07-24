#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int josephus(int n, int k) {
    if(n == 1) return 0;
    return (josephus(n-1, k) + k) % n;
}

void solve() {
    int N;
    cin >> N;
    int survivor = 0;
    int cnt = 0;
    while (N > 1) {
        survivor = josephus(N, 2);
        if(survivor == N-1)
            break;
        N = survivor+1;
        cnt++;
    }
    cout << ' ' << cnt << ' ' << N << '\n';
}

int main() {
    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        cout << "Case " << i << ":";
        solve();
    }
    return 0;
}