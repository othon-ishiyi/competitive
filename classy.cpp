#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int,int>>

using namespace std;

bool mycompare(pair<string, vi> &a, pair<string, vi> &b){
    auto it_a = (a.second).end()-1;
    auto it_b = (b.second).end()-1;

    while(it_a != a.second.begin()-1 && it_b != b.second.begin()-1){
        if(*it_a != *it_b) return *it_a > *it_b;
        else{
            it_a--;
            it_b--;
        }
    }

    while(it_a != a.second.begin()-1){
        if(*it_a) return *it_a > 0;
        it_a--;
    }

    while(it_b != b.second.begin()-1){
        if(*it_b) return *it_b < 0;
        it_b--;
    }

    return a.first < b.first;
}


void solve() {
    int N, i=0;
    vi cl_i;
    cin >> N;
    vvi c(N);
    vector<pair<string, vi>> v(N);

    string line, s, cl, name;

    cin.ignore();
    while(i<N) {
        getline(cin, line);
        stringstream ss(line);
        getline(ss, name, ' ');
        name.pop_back();
        getline(ss, s, ' ');
        stringstream classes(s);
        while(getline(classes, cl, '-')){
            if(cl == "lower")
                cl_i.push_back(-1);
            if(cl == "middle")
                cl_i.push_back(0);
            if(cl == "upper")
                cl_i.push_back(1);
        }

        v[i++] = {name, cl_i};
        cl_i.clear();
    }

    sort(v.begin(), v.end(), mycompare);

    for(auto p: v)
        cout << p.first << '\n';
    cout << "==============================\n";
}

int main() {
    int N;
    cin >> N;
    while(N--)
        solve();
    return 0;
}