#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define pll pair<long, long>
#define fr(num1, num2, i) for (int i = num1; i < num2; i++)
#define rfr(num1, num2, i) for (int i = num1 - 1; i >= num2; i--)
#define F first
#define S second
using namespace std;
void fastio();
void DEBUGGGGGGGGGGGGGGGG();
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
그리디

마지막 마감시간부터 걸리는 시간만큼 빼간다.

T - t 의 값이 다음 마감시간의 값보다 크면 계속해서 빼준다.
그렇지 않으면 다음 값은 다음 마감시간T’- 다음 걸리는시간 t’이 된다.

마감시간부터 시작해서 걸리는 시간만큼뺀다.
만약 뺀값이 이전일의 마감시간보다 크거나 같으면 
더 여유가 있다는 뜻으로 계산된 시간에 걸리는 시간을 빼준다.
하지만 값이 이전일의 마감시간보다 작으면
여유가 없고 빨리 일을 끝내야하기 때문에 
계산된 시간을 버리고 마감시간-걸린시간을 새로운 시간으로 잡는다.
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}

void solve() {
    int n;
    cin >> n;
    vector<pii> v;
    fr(0, n, i) {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }
    sort(v.rbegin(), v.rend());

    int t = v[0].F - v[0].S;
    fr(1, v.size(), i) {
        if (t <= v[i].F) {
            t -= v[i].S;
        } else {
            t = v[i].F - v[i].S;
        }
    }
    if (t < 0)
        cout << -1;
    else
        cout << t;
}

int main() {
    fastio();
    preprocess();
    DEBUGGGGGGGGGGGGGGGG();
    int t;
    t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << t << ": ";
        solve();
    }
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DEBUGGGGGGGGGGGGGGGG() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}