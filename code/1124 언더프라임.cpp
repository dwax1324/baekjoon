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
    소수,dp

    체를 이용하여 수를 구해주고
    소인수 분해를 시켜준뒤 갯수를 세서
    이분탐색으로 그 갯수가 소수인지 센다.

    dp풀이법은 봐도 모르겠다.
    

*/
///////////////////////////////////////////////

void preprocess() {
}
vector<int> v;
void seive() {
    bool vi[100001];
    memset(vi, 0, sizeof(vi));
    for (int i = 2; i * i <= 100000; i++) {
        if (vi[i]) continue;
        for (int j = i * i; j <= 100000; j += i) {
            vi[j] = true;
        }
    }
    fr(i, 2, 100001) {
        if (!vi[i])
            v.push_back(i);
    }
}

int bs(int a) {
    int l = 0;
    int r = v.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] == a) {
            // cout << "a : " << a << " v[mid]: " << v[mid] << '\n';
            return mid;
        } else if (v[mid] < a) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int primefactorize(int a) {
    int cnt = 0;
    while (a > 1) {
        for (auto x : v) {
            if (a % x == 0) {
                // cout << a << " ";
                a /= x;
                cnt++;
                break;
            }
        }
    }
    // cout << '\n';
    return cnt;
}

void solve() {
    int n, m;
    cin >> n >> m;
    seive();
    int cnt = 0;
    // fr(i, 0, 10000) {
    //     if (v[i] > m) break;
    //     cout << v[i] << " ";
    // }
    // cout << '\n';
    fr(i, n, m + 1) {
        int k = primefactorize(i);
        // cout << k << " ";
        if (bs(k) != -1) {
            cnt++;
        }
    }
    cout << cnt;
}
int main() {
    fastio();
    preprocess();
    DEBUG();
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