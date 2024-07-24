    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<vector<int>> vvi;
    typedef pair<int,int> ii;

    void solve() {
        string s1, s2;
        cin >> s1 >> s2;

        int len = min(s1.size(), s2.size());
        int l, r;

        int ans = 0;

        int i;
        for(i=0; i<len; i++) {
            if(s1[i] != s2[i]) {
                l = i;
                break;
            }
        }
        if(i == len) {
            cout << max(0, int(s2.size() - s1.size())) << '\n';
            return;
        }
        for(int i=1; i<=len; i++) {
            if(s1[s1.size()-i] != s2[s2.size()-i]) {
                r = i - 1;
                break;
            }
        }
        if(i == len) {
            cout << max(0, int(s2.size() - s1.size())) << '\n';
            return;
        }

        cout << max(0, int(s2.size() - l - r)) << '\n';


    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        solve();
        return 0;
    }