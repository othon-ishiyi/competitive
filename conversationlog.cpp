#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;


void solve() {
    int N, count_users=0;
    cin >> N;

    unordered_map<string, unordered_set<string>> w_user;
    unordered_map<string, ii> rep_w;
    set<pair<int, string>> ord;

    string s, user, line;

    cin.ignore();

    while(N--){
        getline(cin, line);
        bool is_name = true;
        stringstream ss(line);
        while(getline(ss, s, ' ')){
            if(is_name) {
                user = s;
                is_name = false;
                if(w_user.count(user) == 0){
                    count_users++;
                }
                continue;
            }

            if(!rep_w.count(s))
                rep_w[s] = {0,0};

            rep_w[s].second--;
            if(!w_user[user].count(s)){
                rep_w[s].first++;
            }

            w_user[user].insert(s);
        }
    }

    for(auto &p: rep_w){
        if(p.second.first == count_users){
            ord.insert({p.second.second, p.first});
        }
    }

    if(ord.empty()){
        cout << "ALL CLEAR\n";
        return;
    }

    for(auto &p: ord){
        cout << p.second << '\n';
    }
}

int main() {
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    */

    solve();
    return 0;
}