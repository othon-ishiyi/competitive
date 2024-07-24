#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

bitset<200> a[200];
string s;

string btod(int rowlo, int rowhi, int collo, int colhi) {
    if(collo >= colhi or rowlo >= rowhi) return "";
    if(rowlo == rowhi-1 and collo == colhi-1) return to_string(a[rowlo][collo]);

    vector<string> v(4);

    v[0]= btod(rowlo, (rowlo+rowhi+1)/2, collo, (collo+colhi+1)/2);
    v[1]= btod(rowlo, (rowlo+rowhi+1)/2, (collo+colhi+1)/2, colhi);
    v[2]= btod((rowlo+rowhi+1)/2, rowhi, collo, (collo+colhi+1)/2);
    v[3]= btod((rowlo+rowhi+1)/2, rowhi, (collo+colhi+1)/2, colhi);

    bool all0 = true, all1 = true;

    for(int i=0; i<4; i++) {
        if(v[i] != "1" and v[i] != "") {
            all1 = false;
        }
        if(v[i] != "0" and v[i] != "") {
            all0 = false;
        }
    }

    if(all0) return "0";
    if(all1) return "1";

    string ans = "D";
    for(auto k: v) {
        ans += k;
    }
    return ans;
}

int dtob(int it, int rowlo, int rowhi, int collo, int colhi) {
    if(collo >= colhi or rowlo >= rowhi) return it-1;
    int ans = s[it] - '0';
    if(ans == 0 or ans == 1) {
        for(int i=rowlo; i<rowhi; i++) {
            for(int j=collo; j<colhi; j++) {
                a[i][j] = ans;
            }
        }
        return it;
    }
    it = dtob(it+1, rowlo, (rowlo+rowhi+1)/2, collo, (collo+colhi+1)/2);
    it = dtob(it+1, rowlo, (rowlo+rowhi+1)/2, (collo+colhi+1)/2, colhi);
    it = dtob(it+1, (rowlo+rowhi+1)/2, rowhi, collo, (collo+colhi+1)/2);
    return dtob(it+1, (rowlo+rowhi+1)/2, rowhi, (collo+colhi+1)/2, colhi);
}

void solve(char c) {
    int row, col;
    cin >> row >> col;
    cin >> s;
    if(c == 'B') {
        int it=0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++, it++) {
                a[i][j] = s[it] - '0';
            }
            if(i != row-1 and it >= s.size()) {
                cin >> s;
                it = 0;
            }
        }
        cout << "D  " << row << "  " << col <<'\n';
        cout << btod(0, row, 0, col) << '\n';
    }
    if(c == 'D') {
        cout << "B  " << row << "  " << col <<'\n';
        dtob(0, 0, row, 0, col);
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    while(true) {
        cin >> c;
        if(c == '#') return 0;
        solve(c);
    }
    return 0;
}