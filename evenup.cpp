#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;

void solve() {
    int n, a;
    cin >> n;
    int ans = n;
    stack<int> s;

    while(n--){
        cin >> a;
        if(s.empty()){
            s.push(a);
        }
        else if(((s.top()+a) & 1) == 0){
            s.pop();
            ans -= 2;
        }
        else {
            s.push(a);
        }
    }

    cout << ans;
}

int main() {
    solve();
    return 0;
}