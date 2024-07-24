#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void solve() {
    char mode;
    int id, item;

    map<int, tuple<int, bool, bool>> item_transaction;
    set<int> blocked;


    while(true){
        cin >> mode;
        if(mode == '#') return;

        cin >> id >> item;

        if(blocked.count(id)){
            cout << "IGNORED\n";
            continue;
        }

        auto p = item_transaction.find(item);

        if(p != item_transaction.end()){
            if(mode == 'X'){
                if(get<0>(p->second) != id or get<2>(p->second)){
                    cout << "DENIED\n";
                    blocked.insert(id);
                    continue;
                }
                else{
                    cout << "GRANTED\n";
                    item_transaction[item] = {id, true, false};
                    continue;
                }
            }
            else{
                if(get<1>(p->second) == false or get<0>(p->second) == id){
                    cout << "GRANTED\n";
                    item_transaction[item] = {id, (mode == 'X')+(get<1>(p->second)), (get<0>(p->second) != id)+(get<2>(p->second))};
                    continue;
                }
                else{
                    cout << "DENIED\n";
                    blocked.insert(id);
                    continue;
                }
            }
        }
        else {
            cout << "GRANTED\n";
            item_transaction[item] = {id, (mode == 'X'), false};
        }

    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while(n--){
        solve();
        if(n) cout << '\n';
    }

    return 0;
}
