#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;


void solve(int N, int M) {
    unordered_set<int> s;
    int a, find = 0;
    while(N--){
        cin >> a;
        s.insert(a);
    }
    while(M--){
        cin >> a;
        find += s.count(a);
    }

    cout << find << '\n';

}

int main() {
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    */

    int N, M;
    cin >> N >> M;

    while(N != 0 and M != 0){
        solve(N, M);
        cin >> N >> M;
    }

    return 0;
}