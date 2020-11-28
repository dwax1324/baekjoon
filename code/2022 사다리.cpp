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
    기하
    비율+ 피타고라스를 이용하여
    c에대한 식을 세운다음
    실제 c의 값에 부합하는 c의 식에 왼쪽높이와 오른쪽높이를
    이분탐색으로 찾는다.
*/
///////////////////////////////////////////////

void preprocess() {
}

double x, y, c;
double check(double d) {
    double l = sqrt(x * x - d * d);
    double r = sqrt(y * y - d * d);
    return (l * r) / (r + l);
}

void solve() {
    cin >> x >> y >> c;
    double l = 0;
    double r = min(x, y);
    double mid;
    int cnt = 0;
    while (1) {
        if (cnt++ > 100) break;
        mid = (l + r) / 2;
        if (check(mid) >= c) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(3) << mid;
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