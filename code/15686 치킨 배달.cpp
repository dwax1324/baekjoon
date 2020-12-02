#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pic pair<int, char>
#define pipii pair<int, pii>
#define pll pair<long, long>
#define fr(num1, num2, i) for (int i = num1; i < num2; i++)
#define rfr(num1, num2, i) for (int i = num1 - 1; i >= num2; i--)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define F first
#define S second
using namespace std;
void fastio();
void debug();
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    완탐 !
    
    치킨 배달

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}
int n, m;
vector<pii> v1, v2;

int vi[10001];
int calc(int y, int x) {
    int ret = 0;
    fr(0, sz(v1), i) {
        if (!vi[i]) {
            ret += abs(v1[i].F - y) + abs(v1[i].S - x);
            vi[i] = true;
        }
    }
    // cout << ret << " ";
    return ret;
}
vector<int> ans;
int go(vector<int> picked, int depth) {
    if (depth == m) {
        int ret = 0;
        bool vi[51][51];
        memset(vi, 0, sizeof(vi));
        fr(0, sz(v1), j) {
            int sum = 1 << 30;
            fr(0, sz(picked), i) {
                int chickY = v2[picked[i]].F;
                int chickX = v2[picked[i]].S;
                int homeY = v1[j].F;
                int homeX = v1[j].S;
                int dist = abs(homeY - chickY) + abs(homeX - chickX);
                if (vi[homeY][homeX]) continue;
                sum = min(sum, dist);
                // cout << dist << " ";
            }
            fr(0, sz(picked), i) {
                int chickY = v2[picked[i]].F;
                int chickX = v2[picked[i]].S;
                int homeY = v1[j].F;
                int homeX = v1[j].S;
                int dist = abs(homeY - chickY) + abs(homeX - chickX);
                if (dist == sum) {
                    vi[homeY][homeX] = vi[chickY][chickX] = true;
                    break;
                }
            }
            // cout << sum << " ";
            ret += sum;
        }
        // cout << ret << '\n';

        return ret;
    }

    int k = picked.size() ? picked.back() + 1 : 0;

    int ans = 1 << 30;
    fr(k, sz(v2), i) {
        picked.push_back(i);
        ans = min(ans, go(picked, depth + 1));
        picked.pop_back();
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    fr(0, n, i) {
        fr(0, n, j) {
            int a;
            cin >> a;
            if (a == 1)
                v1.push_back({i, j});
            else if (a == 2)
                v2.push_back({i, j});
        }
    }
    cout << go({}, 0);
}

int main() {
    fastio(), debug(), preprocess();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << t << ": ";
        solve();
    }
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
void fastio() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
}

void debug() {
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
}