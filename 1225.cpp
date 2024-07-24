#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    int N;
    cin >> N;
    vi cnt(10, 0);

    for(int i=1; i<=N; i++) {
        int j=i;
        while(j) {
            cnt[j%10]++;
            j /= 10;
        }
    }

    for(int i=0; i<9; i++) {
        cout << cnt[i] << ' ';
    }
    cout << cnt[9] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    while(N--)
        solve();
    
    return 0;
}