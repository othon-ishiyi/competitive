#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#define LSOne(x) ((x) & -(x))

void solve(int N, int M) {
    vector<ii> v;
    set<ii> s;
    while(M--) {
        int a, b;
        cin >> a >> b;
        if(s.count({a-1, b-1}) == 0) {
            v.push_back({a-1, b-1});
            s.insert({a-1, b-1});
        }
    }

    int ans = 0;

    for(int i=0; i<=(1 << N) - 1; i++) {
        bool valid = true;
        for(auto p: v) {
            if((i & (1 << p.first)) and (i & (1 << p.second))) {
                valid = false;
                break;
            }
        }
        if(valid) ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;

    cin >> N >> M;
    solve(N, M);
    return 0;
}