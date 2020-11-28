#include <bits/stdc++.h>
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
    문자열
    맞는 짝을 다 찾고 표시한다.
    그 후 반복문을 돌면서 표시안된 짝이 서로다르면 2를추가
    같으면 1을추가해서 출력한다.
*/
///////////////////////////////////////////////

void preprocess() {
}

int cnt = 0;
void solve() {
    string s;
    cin >> s;

    if (s[0] == '-') exit(0);
    fr(i, 0, s.size()) {
        if (s[i] == '{') {
            fr(j, i + 1, s.size()) {
                if (s[j] == '}') {
                    s[j] = '@';
                    s[i] = '@';
                    break;
                }
            }
        }
    }

    // fr(i, 0, s.size()) {
    //     cout << s[i];
    // }
    // cout << '\n';
    cnt = 0;
    fr(i, 0, s.size()) {
        if (s[i] != '@') {
            fr(j, i + 1, s.size()) {
                if (s[j] == '@') continue;
                if (s[j] == s[i]) {
                    cnt++;
                    s[i] = '@';
                    s[j] = '@';
                    break;
                } else {
                    s[i] = '@';
                    s[j] = '@';
                    cnt += 2;
                    break;
                }
            }
        }
    }
    // cout << cnt << '\n';
}
int main() {
    fastio();
    preprocess();
    // DEBUG();
    int t;
    // t = 10000;
    // cin >> t;
    int i = 1;
    while (1) {
        solve();
        cout << i++ << ". ";
        cout << cnt << '\n';
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