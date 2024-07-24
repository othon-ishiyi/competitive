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
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> sell;
    priority_queue<int> buy;


    string cmd, s1, s2;
    int price, qty;
    int a = -1, b = -1, s = -1;

    while(n--){
        cin >> cmd >> qty >> s1 >> s2 >> price;
        if(cmd == "buy"){
            while(qty--)
                buy.push(price);
        }
        else{
            while(qty--)
                sell.push(price);
        }

        while(!buy.empty() and !sell.empty() and buy.top() >= sell.top()){
            s = sell.top();
            buy.pop();
            sell.pop();
        }
        b = buy.empty()? -1: buy.top();
        a = sell.empty()? -1: sell.top();

        cout << (a == -1? "-":to_string(a)) << " " << (b == -1? "-":to_string(b)) << " " << (s == -1? "-":to_string(s)) << '\n';
    }
}

int main() {
    int N;
    cin >> N;

    while(N--)
        solve();

    return 0;
}