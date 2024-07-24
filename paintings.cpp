#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

bitset<12> allowed[12], used;
int N;
int ans;
vi sol(12, 0), best_sol(12, INT_MAX);

bool cmp(vi best, vi s) {
    for(int i=0; i<N; i++) {
        if(s[i] < best[i]) {
            return true;
        }
        if(s[i] > best[i]) {
            return false;
        }
    }
    return false;
}

void rb(int col) {
    if(col == N) {
        ans++;
        if(cmp(best_sol, sol)) best_sol = sol;
        return;
    }
    int aux = sol[max(0, col-1)];
    for(int i=0; i<N; i++) {
        if((allowed[aux][i] or col == 0) and !used[i]) {
            sol[col] = i;
            used[i] = 1;
            rb(col+1);
            used[i] = 0;
        }
    }
}

void solve() {
    for(int i=0; i<12; i++) {
        allowed[i].set();
    }
    cin >> N;
    ans = 0;
    sol.assign(12,0);
    best_sol.assign(12, INT_MAX);
    used.reset();
    vector<string> colors(N);
    for(int i=0; i<N; i++) {
        cin >> colors[i];
    }
    int M;
    cin >> M;

    for(int i=0; i<M; i++) {
        int j, k;
        string a, b;
        cin >> a >> b;
        for(j=0; colors[j] != a; j++);
        for(k=0; colors[k] != b; k++);
        allowed[j][k] = 0;
        allowed[k][j] = 0;
    }

    rb(0);
    cout << ans << '\n';
    if(ans != 0) {
        for(int i=0; i<N-1; i++) {
            cout << colors[best_sol[i]] << ' ';
        }
        cout << colors[best_sol[N-1]] << '\n';
    }
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