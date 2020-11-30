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
void 쩜씸나깔껐깥아();
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    그리디

    가장 큰값과 가장 작은값을 묶어서 판다

    어떤수열 1,5,6에 대해서

    세수의 묶음이 두수의 묶음보다 작음을 증명하려면
    세수의 묶음을 최대화시키면 된다.
    
    세 수의 묶음은 중앙값에 의해 결정되므로 1,5,6은
    세 수의 묶음의 값이 최대일 때 값은 3*5=15이다.

    이는 6*2+5 = 17 보다 작으므로 최댓값과 최솟값의 묶음이 최댓값이다.



k<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}

void solve() {
    int n;
    cin >> n;
    deque<int> v;
    fr(0, n, i) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int ans = 0;
    while (1) {
        if (v.size() <= 1) break;
        ans += v[v.size() - 1] * 2;
        v.pop_back();
        v.pop_front();
    }
    if (v.size() == 1) ans += v[0];
    cout << ans;
}

int main() {
    fastio();
    preprocess();
    쩜씸나깔껐깥아();
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

void 쩜씸나깔껐깥아() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}