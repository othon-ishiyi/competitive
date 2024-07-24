#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;

void solve(int n_case) {
    int n, s=0;
    int k;

    cin >> n >> k;

    if((k & ((1<<n)-1)) == ((1<<n)-1))
        printf("Case #%d: ON\n", n_case);
    else
        printf("Case #%d: OFF\n", n_case);
}

int main() {
    int N;
    cin >> N;
    for(int i=1; i<=N;i++){
        solve(i);
    }
    return 0;
}
