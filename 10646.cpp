#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n = 52, y = 0, p = 25;
    vector<string> deck;

    while(n--) {
        string card;
        cin >> card;
        deck.push_back(card);
    }

    for(int i = 0; i < 3; i++) {
        int x;
        x = (isdigit(deck[p][0]) != 0? int(deck[p][0]-'0'): 10);
        y += x;
        deck.erase(deck.begin() + p-1, deck.begin() + p + 10 - x);
    }

    cout << deck[y-1];
}

int main() {
    int n;
    cin >> n;

    while(n--) {
        solve();
    }

    return 0;
}

//Provavelmente n entendi o enunciado fds