#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;

/*
#include <bits/extc++.h> // pbds
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ost;
*/

void solve() {
    unordered_map<string, vector<int>> m;
    string country;
    int N, K, year;

    cin >> N;
    while(N--){
        cin >> country >> year;
        m[country].push_back(year);
    }

    for(auto &p: m){
        sort(p.second.begin(), p.second.end());
    }

    cin>>K;
    while(K--){
        cin >> country >> year;
        cout << m[country][year-1] << '\n';
    }
}

int main() {
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    */

    solve();
    return 0;
}