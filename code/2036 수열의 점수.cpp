#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define pll pair<long, long>
#define fr(num1, num2, i) for (int i = num1; i < num2; i++)
#define rfr(num1, num2, i) for (int i = num1 - 1; i >= num2; i--)
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
using namespace std;
void fastio();
void 쩜씸나깔껐깥아();
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    무조건 절댓값이 큰 두수순으로 곱한다.

    1이면 무조건 더한다 -> 1과 곱하는 거 보다 
    항상 1과 나머지수를 하나씩 뽑는게 더 크다.

    음수에서 절댓값이 큰순으로 곱해나갔을 때
    남는게 있다면 0과 곱한다.


<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> pos, neg;
    bool zero = false;
    fr(0, n, i) {
        ll a;
        cin >> a;
        if (a > 0)
            pos.pb(a);
        else if (a < 0)
            neg.pb(a);
        else
            zero = true;
    }

    sort(all(pos));
    sort(rall(neg));

    ll sum = 0;
    if (sz(pos) % 2 == 1) {
        for (int i = sz(pos) - 1; i >= 1; i -= 2) {
            if (pos[i] == 1) {
                sum += pos[i - 1] + 1;
            } else if (pos[i - 1] == 1) {
                sum += pos[i] + 1;
            } else {
                sum += pos[i] * pos[i - 1];
            }
        }
        sum += pos[0];
    } else {
        if (sz(pos)) {
            for (int i = sz(pos) - 1; i >= 0; i -= 2) {
                if (pos[i] == 1) {
                    sum += pos[i - 1] + 1;
                } else if (pos[i - 1] == 1) {
                    sum += pos[i] + 1;
                } else {
                    sum += pos[i] * pos[i - 1];
                }
            }
        }
    }
    if (sz(neg) % 2 == 1) {
        for (int i = sz(neg) - 1; i >= 1; i -= 2) {
            sum += neg[i] * neg[i - 1];
        }
        if (!zero) {
            sum += neg[0];
        }
    } else {
        if (sz(neg)) {
            for (int i = sz(neg) - 1; i >= 0; i -= 2) {
                sum += neg[i] * neg[i - 1];
            }
        }
    }
    cout << sum;
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