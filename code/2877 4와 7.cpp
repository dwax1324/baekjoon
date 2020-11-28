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
    수학 이진수
    n번째 수 = n+1을 이진수로 나타냈을때의 맨앞을 제외한 0(4),1(7)
*/
///////////////////////////////////////////////

void preprocess() {
}

string bin(int a) {
    string temp = "";
    while (a) {
        temp += (a % 2 == 0 ? '0' : '1');
        a /= 2;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
void solve() {
    int n;
    cin >> n;
    n++;
    string k = bin(n);
    fr(i, 1, k.size()) {
        if (k[i] == '1') {
            cout << 7;
        } else {
            cout << 4;
        }
    }
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