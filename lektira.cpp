#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

void reverse(string &str, int f, int l) {
    int a = (l-f+1)/2;
    for(int i=0; i<a; f++, l--, i++) {
        swap(str[f], str[l]);
    }
}

string getResult(string str, int i, int j) {
    reverse(str, 0, i);
    reverse(str, i+1, j);
    reverse(str, j+1, str.size()-1);
    return str;
}

void solve() {
    string s, lowest;
    cin >> s;

    lowest = s;

    int n = s.size();

    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            string t = getResult(s, i, j);
            if(t < lowest) {
                lowest = t;
            }
        }
    }

    cout << lowest << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}