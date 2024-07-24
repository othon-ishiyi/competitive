#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;


#include <ext/pb_ds/assoc_container.hpp> // pbds
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
tree_order_statistics_node_update> indexed_multiset;


void solve() {
    int n;
    cin >> n;
    indexed_multiset s;
    ll sum=0;

    for(int i=1; i<=n; i++){
        ll a;
        cin >> a;
        s.insert(a);

        if(i & 1) {
            sum += *s.find_by_order(i/2);
        }
        else {
            sum += (*s.find_by_order(i/2) + *s.find_by_order(i/2-1))/2;
        }
    }

    cout << sum << '\n';


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    while(N--){
        solve();
    }
    return 0;
}