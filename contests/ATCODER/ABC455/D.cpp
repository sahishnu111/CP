#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

struct Card {
    int above = 0;
    int under = 0;
};

class game {
public:
    vector<Card> cards;
    vector<int> pilesBottom;
    vector<int> cardToPile;
    int N;

    game(int n) {
        N = n;
        cards.resize(n + 1);
        pilesBottom.resize(n + 1);
        cardToPile.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            pilesBottom[i] = i;
            cardToPile[i] = i;
        }
    }

    void mv(int C, int P) {
        if (cards[C].under == 0) {
            int originalPile = cardToPile[C];
            pilesBottom[originalPile] = 0;
        } else {
            cards[cards[C].under].above = 0;
        }

        cards[C].under = P;
        cards[P].above = C;
    }

    void printResult() {
        for (int i = 1; i <= N; i++) {
            int c = 0;
            int curr = pilesBottom[i];
            while (curr != 0) {
                c++;
                curr = cards[curr].above;
            }
            cout << c << (i == N ? "" : " ");
        }
        cout << endl;
    }
};

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    game g(n);
    while (q--) {
        int c, p;
        cin >> c >> p;
        g.mv(c, p);
    }

    g.printResult();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = 1;
    while (test--) {
        solve();
    }
    return 0;
}