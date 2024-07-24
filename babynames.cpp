#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

#include <ext/pb_ds/assoc_container.hpp> // pbds
using namespace __gnu_pbds;
typedef tree<string, null_type, greater<string>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

void solve() {
    indexed_set masc, fem;
    string cmd, name1, name2;
    int gender;
    while(true){
        cin >> cmd;
        if(cmd == "0") return;
        if(cmd == "1") {
            cin >> name1 >> gender;

            if(gender != 2){
                masc.insert(name1);
            }
            if(gender != 1){
                fem.insert(name1);
            }
            continue;
        }
        if(cmd == "2") {
            cin >> name1;
            
            auto it = masc.find_by_order(masc.order_of_key(name1));
            if(*it == name1)
                masc.erase(it);
            it = fem.find_by_order(fem.order_of_key(name1));
            if(*it == name1)
                fem.erase(fem.find_by_order(fem.order_of_key(name1)));
            continue;
        }

        cin >> name1 >> name2 >> gender;
        char c = name2.back();
        if(c == 'A'){
            name2.pop_back();
        }
        else{
            name2[name2.size()-1] = c-1;
        }
        int ans = 0;
        if(gender != 2)
            ans += masc.order_of_key(name1) - masc.order_of_key(name2);
        if(gender != 1)
            ans += fem.order_of_key(name1) - fem.order_of_key(name2);
        cout << ans << '\n';

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}