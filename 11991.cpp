#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve(int n, int m) {
    vector<int> g[100001];
    unordered_map<int, int> value;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        if(!value.count(a))
            value[a] = cnt++;   
        g[value[a]].push_back(i+1);
    }

    while(m--){
        int k, v;
        cin >> k >> v;
        if(k > g[value[v]].size())
            cout << 0 << '\n';
        else
            cout << g[value[v]][k-1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    
    while(cin >> n >> m)
    solve(n, m);
    return 0;
}