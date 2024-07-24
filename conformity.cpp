#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;


void solve() {
    string s;
    int N, popular=0, qty=0;
    cin >> N;
    unordered_map<string, int> m;

    vector<int> v(5);

    while(N--){
        cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
        sort(v.begin(), v.end());
        s = "";

        for(int i : v){
            s += to_string(i);
        }
        m[s]++;
        if(m[s] > popular){
            qty = popular = m[s];
        }
        else if(m[s] == popular){
            qty += m[s];
        }
    }

    cout << qty;
}

int main() {
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    */

    solve();
    return 0;
}