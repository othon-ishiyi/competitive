#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;

void solve() {
    int n, k;
    cin >> n >> k;
    string query;
    stack<int> s;
    s.push(0);

    while(k--){
        cin >> query;
        if(query == "undo"){
            int a;
            cin >> a;
            while(a--)
                s.pop();
        }
        else {
            int a = stoi(query);

        while(a+s.top()<0)
                a += n;
            a = (a+s.top())%n;
            s.push(a);
        }
    }

    cout << s.top();
}

int main() {
    solve();
    return 0;
}