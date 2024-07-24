#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

/*
#include <bits/extc++.h> // pbds
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ost;
*/

void solve() {
    int n, awk;
    cin >> n;
    awk = n;

    unordered_map<int, int> last_person;
    unordered_map<int, int> mindist;

    for(int i=0; i<n; i++){
        int l;
        cin >> l;

        if(last_person.count(l)){
            mindist[l] = min(mindist[l], i-last_person[l]);
        }

        else{
            mindist[l] = n;
        }

        last_person[l] = i;
        awk = min(awk, mindist[l]);
    }

    cout << awk;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}