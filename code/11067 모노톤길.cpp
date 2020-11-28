#include <bits/stdc++.h>
//////////////////////////////////////////////
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define fr(i, num1, num2) for (int i = num1; i < num2; i++)
#define rfr(i, num1, num2) for (int i = num1 - 1; i >= num2; i--)
#define F first
#define S second
using namespace std;
void fastio();
void DEBUG();
///////////////////////////////////////////////
/*
    구현
    모노톤길의 정의를 잘 생각해봐야 한다.
    되돌아가는길은 없고 갈등(어느쪽 길로 가야할지)이 생기는 길도 없다.
    그럼 그냥 길을 따라서 가면된다.

    x좌표별로 벡터에 넣어주고 정렬시킨다.
    그럼 시작점은 첫번째 원소거나 마지막 원소다.
    이 길을 따라가면 된다.

*/
///////////////////////////////////////////////

void preprocess() {
}

void solve() {
    int n;
    cin >> n;
    vector<int> v[100001];
    int MAXA = 0;
    fr(i, 0, n) {
        int a, b;
        cin >> a >> b;
        MAXA = max(a, MAXA);
        v[a].push_back(b);
    }
    pii arr[100001];
    int cnt = 1;
    int x = 0;
    int y = 0;
    int next = 0;
    fr(i, 0, MAXA + 1) {
        if (v[i].size()) {
            sort(v[i].begin(), v[i].end());
        }
        int j;
        if (v[i].size() && v[i][0] == next) {
            j = 0;
            while (1) {
                if (j == v[i].size()) break;
                // cout << "i is :" << i << '\n';
                // cout << i << " " << j << "v[i][j] is :" << v[i][j] << '\n';
                arr[cnt++] = {i, v[i][j]};
                next = v[i][j];
                j++;
                // cout << "next is : " << next << '\n';
            }
        } else if (v[i].size() && v[i][v[i].size() - 1] == next) {
            j = v[i].size() - 1;
            while (1) {
                if (j == -1) break;
                arr[cnt++] = {i, v[i][j]};
                next = v[i][j];
                j--;
                // cout << i << "v[i][j] is :" << v[i][j] << '\n';
                // cout << "next is :" << next << '\n';
            }
        }
    }
    int q;
    cin >> q;
    fr(i, 0, q) {
        int a;
        cin >>
            a;
        cout << arr[a].F << " " << arr[a].S << '\n';
    }
}
int main() {
    fastio();
    preprocess();
    DEBUG();
    int t;
    t = 1;
    cin >> t;
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