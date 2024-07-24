#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vii;

void solve() {
    int n, i=1;
    string sentence="";

    cin >> n;
    cin >> sentence;

    int total = (1 << (n+1));

    for(char c: sentence){
        if(c == 'L')
            i = i << 1;
        else
            i = (i << 1) + 1;
    }

    cout << total - i;
}

int main() {
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    */
    solve();
    return 0;
}