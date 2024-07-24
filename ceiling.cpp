#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

class Node {
public:
    Node* l;
    Node* r;
    int val;

    Node(int n) {
        val = n;
        l = r = nullptr;
    }

    void insert(int n) {
        if(n < val) {
            if(l != nullptr) l->insert(n);
            else {
                l = new Node(n);
            }
        }
        else {
            if(r != nullptr) r->insert(n);
            else {
                r = new Node(n);
            }
        }
    }

    Node(vi &v) {
        val = v[0];
        l = r = nullptr;
        for(int i=1; i<v.size(); i++) {
            insert(v[i]);
        }
    }

    string format() {
        string s="";
        if(l != nullptr) {
            s += "L" + l->format();
        }
        if(r != nullptr) {
            s += "R" + r->format();
        }
        return s + "U";
    }
};

void solve() {
    int N, k;
    cin >> N >> k;
    vector<Node> v;
    vi val(k);
    for(int n=0; n<N; n++) {
        for(int i=0; i<k; i++) {
            cin >> val[i];
        }
        v.push_back(Node(val));
    }

    set<string> s;
    for(Node &i: v) {
        s.insert(i.format());
    }

    cout << s.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}