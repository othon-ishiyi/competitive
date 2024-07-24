    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<vector<int>> vvi;
    typedef vector<pair<int,int>> vii;

    void solve() {
        int n, a;
        cin >> n;
        stack<string> s;
        string query;

        while(n--){
            cin >> query;
            if(query[0] == 'S'){
                string name;
                cin >> name;
                s.push(name);
            }

            else if(query[0] == 'K'){
                if(!s.empty())
                    s.pop();
            }

            else{
                if(!s.empty())
                    cout << s.top() << "\n";
                else
                    cout << "Not in a dream\n";
            }
        }
    }

    int main() {
        solve();
        return 0;
    }