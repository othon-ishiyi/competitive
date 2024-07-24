#include <bits/stdc++.h>
#define ll long long

using namespace std;

class player{
public:
    void take(player &p) {
        v2->insert(v2->end(), p.v2->begin(), p.v2->end());
        p.v2->clear();
    }
    char play() {
        char c = v1->front();
        v1->erase(v1->begin());
        v2->push_back(c);

        return c;
    }

    void change() {
        vector<char> *aux;
        aux = v1;
        v1 = v2;
        v2 = aux;
    }

    void print() {
        for(auto it = v2->cend() - 1; it >= v2->begin(); it--) {
            printf("%c", *it);
        }
        printf("\n");
    }

    string name;
    vector<char> *v1 = new vector<char>(), *v2 = new vector<char>();
};

void solve() {
    player p1, p2;
    string s1, s2;
    int n = 1000;

    p1.name = "Jane";
    p2.name = "John";

    cin >> s1 >> s2;

    for(char c : s1){
        p1.v1->push_back(c);
    }
    for(char c : s2){
        p2.v1->push_back(c);
    }

    while(n--) {
        if(p1.play() == p2.play()) {
            if(random()/141%2 == 0) {
                p1.take(p2);
                cout << "Snap! for " << p1.name << ": ";
                p1.print();
            }
            else {
                p2.take(p1);
                cout << "Snap! for " << p2.name << ": ";
                p2.print();
            }
        }

        if(p1.v1->empty()) {
            p1.change();
        }
        if(p2.v1->empty()) {
            p2.change();
        }

        if(p1.v1->empty() && p1.v2->empty()) {
            cout << p2.name << " wins.\n\n";
            return;
        }

        if(p2.v1->empty() && p2.v2->empty()) {
            cout << p1.name << " wins.\n\n";
            return;
        }
    }

    printf("Keeps going and going ...\n\n");
}

int main() {
    int n;
    cin >> n;

    while(n--){
        solve();
    }

    return 0;
}