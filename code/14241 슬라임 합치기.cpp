#include <bits/stdc++.h>
//////////////////////////////////////////////
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define fr(i, num1, num2) for (int i = num1; i < num2; i++)
#define rfr(i, num1, num2) for (int i = num1 - 1; i >= num2; i--)
#define a first
#define b second
using namespace std;
void fastio();
void DEBUG();
///////////////////////////////////////////////
/*
    그리디
    곱셈은 수가 커질수록 훨씬 커지기 때문에
    큰수부터 더해준다.
*/
///////////////////////////////////////////////

void preprocess() {
}

void solve() {
    int n;
    cin >> n;
    priority_queue<int> pq;
    fr(i, 0, n) {
        int a;
        cin >> a;
        pq.push(a);
    }
    int k = pq.top();
    pq.pop();
    int score = 0;
    while (pq.size()) {
        score += (k * pq.top());
        k += pq.top();
        pq.pop();
    }
    cout << score;
}
int main() {
    fastio();
    preprocess();
    // DEBUG();
    int t;
    t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << t << ": ";
        solve();
    }
}

///////////////////////////////////////////////
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DEBUG() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}