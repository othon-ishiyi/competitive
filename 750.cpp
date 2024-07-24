#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

int cnt = 0;
vi row(8, 0);
int a, b;

bool canPlace(int r, int col) {
    for(int c=0; c<col; c++) {
        if(r == row[c] or abs(c-col) == abs(r-row[c])) {
            return false;
        }
    }
    return true;
}

void backtrack(int col) {
    if(col == 8 and row[b] == a) {
        cnt++;
        return;
    }
    for(int i=0; i<8; i++) {
        if(canPlace(i, col)) {
            row[col] = i;
            backtrack(col+1);
        }
    }
}

void solve() {
    cin >> a >> b;
    a--; b--;
    backtrack(0);
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}