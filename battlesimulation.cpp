#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s;
    regex pattern("RBL|RLB|BRL|BLR|LRB|LBR");
    smatch match;

    cin >> s;
    s = regex_replace(s, pattern, "C");
    s = regex_replace(s, regex("R"), "S");
    s = regex_replace(s, regex("B"), "K");
    s = regex_replace(s, regex("L"), "H");
    cout << s;
}
    
int main() {
    solve();
    return 0;
}